#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
"You are given a stream of sensor observations from a vehicle. 
Each observation has a timestamp and a reprojection error. 
Implement a sliding window that computes the rolling average reprojection error over the last N observations, 
and flags the vehicle if the rolling average exceeds a threshold."
*/

/*
observations = [{t=1, error=0.4}, {t=2, error=0.5}, {t=3, error=0.3}, {t=4, error=1.2}, {t=5, error=1.4}, {t=6, error=1.3}]
N = 3
threshold = 1.0
*/

struct Observation
{
    int time;
    double error;
};

struct window_result
{
    bool flagged;
    double flag_timestamp;
    double rolling_avg;
};

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

int main()
{
    vector<Observation> observations = {{1,0.4},{2,0.5},{3,0.3},{4,1.2},{5,1.4},{6,1.3}};
    auto result = sliding_window_check(observations, 3, 1.0);
    cout << result.flag_timestamp << endl;
    cout << result.flagged << endl;
    cout << result.rolling_avg << endl;
    return 0;
}