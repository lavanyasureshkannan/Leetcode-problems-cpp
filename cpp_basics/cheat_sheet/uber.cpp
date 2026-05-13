#include <iostream>
#include <vector>
using namespace std;

double Mean_reprojection_error(vector<vector<double>>& observed_pts, vector<vector<double>>& projected_points)
{
    // edge case
    if(observed_pts.size() == 0 || observed_pts.size() != projected_points.size()) return -1;
    double total_error = 0.0;
    int n = observed_pts.size();
    for(size_t i=0; i<observed_pts.size(); i++)
    {
        double dx = observed_pts[i][0] - projected_points[i][0];
        double dy = observed_pts[i][1] - projected_points[i][0];
        double curr_error = sqrt((dx * dx) + (dy * dy));
        total_error += curr_error;
    }
    return (total_error/n);
}

vector<pair<double, double>> project_3d_points(vector<vector<double>>& points, 
                                              const double fx, const double fy,
                                              const double cx, const double cy,
                                              vector<vector<double>>& R,
                                              vector<double>& t)
{
    vector<pair<double,double>> result;
    for(size_t i=0; i<points.size(); i++)
    {
        if(points[i].size() != 3) continue;
        double X = points[i][0];
        double Y = points[i][1];
        double Z = points[i][2];

        // 1. Apply rotation and translation
        double Xc = R[0][0]*X + R[0][1]*Y + R[0][2]*Z + t[0];
        double Yc = R[1][0]*X + R[1][1]*Y + R[1][2]*Z + t[1];
        double Zc = R[2][0]*X + R[2][1]*Y + R[2][2]*Z + t[2];  

        // 2. Skip invalid detections
        if(Zc <= 0 ) continue;
        double u = fx * (Xc/Zc) + cx;
        double v = fy * (Yc/Zc) + cy;
        result.push_back({u,v});
    }
    return result;
}


bool world_to_pixel(const Vec3& world_points, 
                    const CameraIntrinsics& k, 
                    double R[3][3],
                    double T[3], 
                    int img_width, int img_height,
                    Vec2& outpixel)
{
    double X = world_points.x;
    double Y = world_points.y;
    double Z = world_points.z;

    // rigid body transformation
    double Xc = R[0][0]*X + R[0][1]*Y + R[0][2]*Z + T[0];
    double Yc = R[1][0]*X + R[1][1]*Y + R[1][2]*Z + T[1];
    double Zc = R[2][0]*X + R[2][1]*Y + R[2][2]*Z + T[2];

    if(Zc <= 0) return false;
    
    double x_n = (Xc/Zc);
    double y_n = (Yc/Zc);

    double u = k.fx * x_n + k.cx;
    double v = k.fy * y_n + k.cy;
    
    if(u<0 || v<0 || u>=img_width || v>=img_height) return false;
    
    outpixel.u = u;
    outpixel.v = v;
}


window_result sliding_window_check(vector<Observation>& observations, int N, double threshold)
{
    deque<double> dq;
    window_result result;
    for(size_t i=0; i<observations.size(); i++)
    {
        dq.push_back(observations[i].error);
        if(dq.size() > N) dq.pop_front();
        if(dq.size() == N)
        {
            double sum = 0.0;
            for(double e:dq) sum += e;
            double avg = sum / N;
            
            result.rolling_avg = avg;
            if(avg > threshold)
            {
                result.flag_timestamp = true;
                result.flagged = observations[i].time;
                return result;
            }
        }
    }
    return result;
}



/*
R = identity
t = (1, 2, 3)
If T moves a point FROM world TO camera:
p_cam = R * p_world + t
Then T_inv moves it back FROM camera TO world:
p_world = R^T * p_cam - R^T * t
        = R^T * (p_cam - t)
*/

struct Mat4
{
    double data[4][4];
};

struct Vec3
{
    double x,y,z;    
};

Mat4 create_transform(const double R[3][3], const double t[3])
{
    Mat4 T;
    for(size_t i=0; i<4; i++)
    {
        for(size_t j=0; j<4; j++)
        {
            T.data[i][j] = 0.0;
        }
    }

    // copy R
    for(size_t i=0; i<3; i++)
    {
        for(size_t j=0; j<3; j++)
        {
            T.data[i][j] = R[i][j];
        }
    }
    // copy t
    T.data[0][3] = t[1];
    T.data[1][3] = t[2];
    T.data[2][3] = t[3];

    // last colum
    T.data[3][3] = 1.0;

    return T;
}


Vec3 transform_points(Mat4& T, Vec3& points)
{
    double X = points.x;
    double Y = points.y;
    double Z = points.z;

    double Xc = T.data[0][0]*X + T.data[0][1]*Y + T.data[0][2]*Z + T.data[0][3];
    double Yc = T.data[1][0]*X + T.data[1][1]*Y + T.data[1][2]*Z + T.data[2][3];
    double Zc = T.data[2][0]*X + T.data[2][1]*Y + T.data[2][2]*Z + T.data[2][3];

    return Vec3{Xc,Yc,Zc};
}


Mat4 calculate_inverse(const Mat4& T)
{
    double R[3][3];
    double t[3];

    for(size_t i=0; i<3; i++)
    {
        for(size_t j=0; j<3; j++)
        {
            R[i][j] = T.data[i][j];
        }
    }

    t[0] = T.data[0][3];
    t[1] = T.data[1][3];
    t[2] = T.data[2][3];

    double R_inv[3][3];

    // R inverse = R transpose
    for(size_t i=0; i<3; i++)
    {
        for(size_t j=0; j<3; j++)
        {
            R_inv[i][j] = R[j][i];
        }
    }

    // t_inv = -(R_inv * t)
    double t_inv[3];
    t_inv[0] = -(R_inv[0][0]*t[0] + R_inv[0][1]*t[1] + R_inv[0][2]*t[2]);
    t_inv[1] = -(R_inv[1][0]*t[0] + R_inv[1][1]*t[1] + R_inv[1][2]*t[2]);
    t_inv[2] = -(R_inv[2][0]*t[0] + R_inv[2][1]*t[1] + R_inv[2][2]*t[2]);

    return create_transform(R_inv, t_inv);
}

int main()
{
    double R[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    double t[3]    = {1.0, 2.0, 3.0};

    // Build transform
    Mat4 T = make_transform(R, t);

    // Transform point (5, 6, 7)
    Vec3 point     = {5.0, 6.0, 7.0};
    Vec3 result    = transform_point(T, point);

    cout << "Transformed: ("
         << result.x << ", "
         << result.y << ", "
         << result.z << ")\n";
    // Expected: (6, 8, 10)

    // Invert and transform back
    Mat4 T_inv      = invert_transform(T);
    Vec3 recovered  = transform_point(T_inv, result);

    return 0;
}


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// ============================================================
// DATA TYPES
// ============================================================

enum class Status { NOMINAL, DRIFTING, FLAGGED };

struct Observation {
    string vehicle_id;
    double reprojection_error;
    double timestamp;
};

struct VehicleHealth {
    Status status;
    double latest_error;
    int    consecutive_count;
};

struct FleetSummary {
    int total;
    int nominal;
    int drifting;
    int flagged;
    vector<string> flagged_vehicles;
};

// ============================================================
// CALIBRATION MONITOR
// ============================================================

class CalibrationMonitor {
public:

    // Config
    CalibrationMonitor(double threshold  = 1.0,
                       double baseline   = 0.5,
                       int    window     = 3)
        : threshold_(threshold)
        , baseline_(baseline)
        , window_(window) {}

    // Accept new observation
    void update(const Observation& obs) {

        // Get or create vehicle state
        auto& health = fleet_[obs.vehicle_id];

        // Already flagged — don't update
        if (health.status == Status::FLAGGED) return;

        health.latest_error = obs.reprojection_error;

        // Check drift
        if (obs.reprojection_error > threshold_) {
            health.consecutive_count++;

            if (health.consecutive_count >= window_) {
                health.status = Status::FLAGGED;
            } else {
                health.status = Status::DRIFTING;
            }
        } else {
            // Good observation — reset
            health.consecutive_count = 0;
            health.status = Status::NOMINAL;
        }
    }

    // Get single vehicle status
    Status get_status(const string& vehicle_id) const {
        auto it = fleet_.find(vehicle_id);
        if (it == fleet_.end()) return Status::NOMINAL;
        return it->second.status;
    }

    // Fleet health summary
    FleetSummary summary() const {
        FleetSummary fs;
        fs.total    = fleet_.size();
        fs.nominal  = 0;
        fs.drifting = 0;
        fs.flagged  = 0;

        for (const auto& kv : fleet_) {
            switch (kv.second.status) {
                case Status::NOMINAL:  fs.nominal++;  break;
                case Status::DRIFTING: fs.drifting++; break;
                case Status::FLAGGED:
                    fs.flagged++;
                    fs.flagged_vehicles.push_back(kv.first);
                    break;
            }
        }
        return fs;
    }

    // Is drift systemic across fleet?
    bool is_systemic(double pct = 0.7) const {
        if (fleet_.empty()) return false;
        int drifting = 0;
        for (const auto& kv : fleet_) {
            if (kv.second.status != Status::NOMINAL)
                drifting++;
        }
        return (double)drifting / fleet_.size() >= pct;
    }

private:
    double threshold_;
    double baseline_;
    int    window_;
    unordered_map<string, VehicleHealth> fleet_;
};

// ============================================================
// MAIN
// ============================================================

int main()
{
    CalibrationMonitor monitor(1.0, 0.5, 3);

    // V001 — 3 consecutive drifts → FLAGGED
    monitor.update({"V001", 1.2, 1});
    monitor.update({"V001", 1.3, 2});
    monitor.update({"V001", 1.1, 3});

    // V002 — drift then nominal → resets to NOMINAL
    monitor.update({"V002", 1.5, 1});
    monitor.update({"V002", 0.3, 2});

    // V003 — all nominal
    monitor.update({"V003", 0.4, 1});
    monitor.update({"V003", 0.3, 2});

    // Print fleet summary
    auto fs = monitor.summary();
    cout << "Total:    " << fs.total    << endl;
    cout << "Nominal:  " << fs.nominal  << endl;
    cout << "Drifting: " << fs.drifting << endl;
    cout << "Flagged:  " << fs.flagged  << endl;
    cout << "Flagged vehicles: ";
    for (auto& v : fs.flagged_vehicles) cout << v << " ";
    cout << endl;

    cout << "Systemic: " << (monitor.is_systemic() ? "YES" : "NO") << endl;

    return 0;
}

class TimeMap
{
    public:
    TimeMap() {}

    unordered_map<string, vector<pair<int,string>>> mp;
    void set(string key, string value, int time)
    {
        mp[key].emplace_back(time, value); // mp["foo"] = {{"bar",1},{"bar2,2"} ...}
    }

    string get(string key, int time)
    {
        auto &values = mp[key];
        int left = 0;
        int right = values.size() - 1;
        string result = "";
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(values[mid].first <= time)
            {
                result = values[mid].second;
                left = mid + 1;
            }
            right = mid - 1;
        }
        return result;
    }
};


int bus_routes(vector<vector<int>>& routes, int source, int target)
{
    // base case
    if(source == target) return 0;
    // 1. build an adj list from the routes
    unordered_map<int, vector<int>> stop_to_buses;
    for(size_t route=0; route<routes.size(); route++)
    {
        for(size_t stop:routes[route])
        {
            stop_to_buses[stop].push_back(route);
        }
    }
    /*
        stops    bus
          1       0
          2       0
          7       0,1
          3       1
          6       1
    */

    // 2. Look for the bus that takes in the source stop
    queue<int> q;
    unordered_set<int> visited;
    for(auto route : stop_to_buses[source]) 
    {
        q.push(route); // bus 0 takes it -> from stop_to_bus list
        visited.insert(route); // marked
    }
    int bus_count = 1;

    // 3. jump into the q
    while(!q.empty())
    {
        int q_size = q.size();
        for(size_t i=0; i<q_size; i++)
        {
            int bus = q.front();
            q.pop();

            // 4. Get all the stops that the bus takes and see if it reaches the target
            for(auto stop : routes[bus])
            {
                if(stop == target)
                {
                    return bus_count;
                }
                // 5. If not push the stops to the q
                for(auto nextRoute : stop_to_buses[stop])
                {
                    if(!visited.count(nextRoute))
                    {
                        visited.insert(nextRoute);
                        q.push(nextRoute);
                    }
                }
            }

        }
        bus_count ++;
    }
    return -1;
}

class LRU_Cache
{
    private:
    list<pair<int,int>>cache; // key, value
    unordered_map<int, list<pair<int, int>>::iterator> mp; // key and a pointer to the list 
                                                                // points to (1,10) inside list
    int capacity;

    public:
    LRU_Cache(int cap)
    {
        capacity = cap;
    }

    int get(int key)
    {
        if(mp.find(key) == mp.end()) return -1;
        // move accessed node to the front
        auto it  = mp[key];
        int value = it->second; // {key, value}

        cache.erase(it);
        cache.push_front({key,value});
        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int val)
    {
        // find if it is in the map and erase it 
        if(mp.find(key) != mp.end()) 
        {
            cache.erase(mp[key]);
        }
        else if(cache.size() == capacity)
        {
            // remove the least used 
            auto last_used = cache.back();
            mp.erase(last_used.first);
            cache.pop_back();
        }
        // insert the new val in the front
        cache.push_front({key,val});
        mp[key] = cache.begin();
    }
};

void dfs(vector<vector<int>>& isConnected, size_t i, vector<bool>& visit)
{
    visit[i] = true;
    // From i city, find all the connected cities
    // similar to grid where we traverse left, right, up, down
    // here we traverse inside the cities and look if it is connected or not
    for(size_t j=0; j<isConnected.size(); j++) 
    {
        if(isConnected[i][j] == 1 && !visit[j])
        {
            dfs(isConnected,j,visit);
        }
    }
}


int number_of_provinces(vector<vector<int>>& isConnected)
{
    int num_of_provinces = 0;
    int n = isConnected.size();
    // 1. keep track of the visisted
    vector<bool> visited(n, false);
    // 2. Iterate thorugh the cities    
    for(size_t i=0; i<n; i++) 
    {
        // 3. Increase the number of province if not in visisted
        if(!visited[i])
        {
            num_of_provinces ++;
            dfs(isConnected, i, visited);
        }
    }
    return num_of_provinces;
}
int meeting_rooms(vector<vector<int>>& intervals)
{
    if(intervals.size() == 0) return 0;
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> pq; // keeep track of the end time
    pq.push(intervals[0][1]);
    for(int i=1; i<intervals.size(); i++)
    {
        int start_time = intervals[i][0];
        int end_time = intervals[i][1];
        if(start_time >= pq.top()) // pq.top -> smallest end time
        {
            pq.pop();
        }
        pq.push(end_time);
    }
    return pq.size();
}


Node* merge_k_sorted(vector<Node*>& lists)
{
    vector<int> nodes;
    for(Node* i: lists)
    {
        while(i)
        {
            nodes.push_back(i->val);
            i = i->next;
        }
    }
    sort(nodes.begin(), nodes.end());
    Node* dummy = new Node(0);
    Node* curr_node = dummy;
    for(int i: nodes)
    {
        curr_node->next = new Node(i);
        curr_node = curr_node->next;
    }
    return curr_node->next;
}

int longest_repeating_char(string s, int k)
{
    int freq[26] = {0};
    int left = 0;
    int N = s.length();
    int maxi = 0;
    int max_freq = 0;
    for(int right=0; right<N; right++)
    {
        // keep track of the frequencies freq[A] - 3
        freq[s[right] - 'A']++;
        // track of freq count 
        max_freq = max(max_freq, freq[s[right] - 'A']); 
        // main logic
        int curr_window = right - left + 1;
        // shrinking the window part
        if((curr_window - max_freq) > k)
        {
            freq[s[left] - 'A'] --;
            left ++;
        }
        maxi = max(maxi, right - left + 1);
    }    
    return maxi;
}


int maximum_points_in_card(vector<int>& card_points, int k)
{
    // 1. calculate the total sum
    size_t n = card_points.size();
    int total_points = 0;
    for(size_t i = 0; i < n; i++)
    {
        total_points += card_points[i];
    }
    // base case
    if (k == n) return total_points;

    // 2. calculate the curr window size
    size_t window_size = n - k;
    // 3. calculate the curr window sum
    int curr_window_sum = 0;
    for(size_t i = 0; i<window_size; i++)
    {
        curr_window_sum += card_points[i];
    }
    int min_window_sum = curr_window_sum;
    // 4. sliding window
    for(size_t i = window_size; i<n; i++)
    {
        curr_window_sum += card_points[i]; // adding the next element
        curr_window_sum -= card_points[i-window_size]; // remove the old element
        min_window_sum = min(curr_window_sum, min_window_sum);
    }

    // 5. return total points - min_window_sum
    return (total_points - min_window_sum);
}


vector<int> sliding_window_maxi(vector<int>& nums, int k)
{
    vector<int> result;
    deque<int> dq;
    for(int i=0; i<nums.size(); i++)
    {
        // removing the useless elements
        if(!dq.empty() && dq.front() < i-k+1) 
        {
            dq.pop_front();
        }
        // removing the smaller elements
        while(!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        // if window is ready take the max out of it
        if(i >= k-1)
        {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}

