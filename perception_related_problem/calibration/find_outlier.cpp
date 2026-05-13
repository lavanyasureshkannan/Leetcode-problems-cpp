#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
"Given a list of calibration results from multiple vehicles of the same model, find the outliers.
A vehicle is an outlier if its reprojection error is more than 2 standard deviations away from the fleet mean."
vehicles = [
  {"V001", 0.4},
  {"V002", 0.5},
  {"V003", 0.3},
  {"V004", 2.8},  ← outlier
  {"V005", 0.4}
]

mean   = 0.88
std    = 0.98
2*std  = 1.96

output → ["V004"]
*/

struct VehicleCalibration
{
    string vehID;
    double reproejction_error;
};


vector<string> outliers(vector<VehicleCalibration>& vehicles)
{
    double mean = 0.0;
    
    for(size_t i=0; i<vehicles.size(); i++)
    {
        mean += vehicles[i].reproejction_error;
    }
    mean = mean / vehicles.size();
    
    double variance = 0.0;
    for(size_t i=0; i<vehicles.size(); i++)
    {
        double square_diff = ((vehicles[i].reproejction_error - mean) * 
                                    (vehicles[i].reproejction_error - mean));
        variance += square_diff;
    }
    variance = variance / vehicles.size();

    double std_deviation = sqrt(variance);

    vector<string> result;
    for(size_t i=0; i<vehicles.size(); i++)
    {
        if(vehicles[i].reproejction_error >=  mean + 2*(std_deviation))
        {
            result.push_back(vehicles[i].vehID);
        }
    }
    return result;
}

int main()
{
    vector<VehicleCalibration>vehicles = {{"V001", 0.4},{"V002", 0.5},{"V003", 0.3},{"V004", 5.0},{"V005", 0.4}};
    vector<string> result = outliers(vehicles);
    for(size_t i=0; i<result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}