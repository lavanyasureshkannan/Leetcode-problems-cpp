#include <iostream>
#include <vector>
using namespace std;

/*
"Given a time series of reprojection errors for a single vehicle, 
detect if calibration has drifted.
Drift = error exceeds threshold for N consecutive observations."

Example:
errors    = [0.4, 0.5, 1.2, 1.3, 1.1, 0.4]
threshold = 1.0
N         = 3

output → drifted = true, drift_start_index = 2
*/

struct Driftdetector
{
    bool drifted;
    int drift_start_index;
};

Driftdetector detect_drift(const vector<double>& errors, double threshold, int N)
{
    int count = 0;
    int start_streak = -1;
    Driftdetector d;
    for(size_t i=0; i<errors.size(); i++)
    {
        if(errors[i] > threshold)
        {
            if(count == 0) start_streak = i;
            count ++;
            if(count >= N)
            {
                d.drift_start_index = start_streak;
                d.drifted = true;
            }
        }
        else 
        {
            count = 0;
            start_streak = -1;
        }
    }
    return d;
}



int main()
{
    vector<double>errors = {0.4, 0.5, 1.2, 1.3, 1.1, 0.4};
    double threshold = 1.0;
    int N = 3;
    auto result = detect_drift(errors, threshold, N);
    cout << result.drift_start_index << endl;
    cout << result.drifted << endl;
    return 0;
}