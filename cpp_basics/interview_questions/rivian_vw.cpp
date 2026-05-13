#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int buffer_size = 5;
void circular_buffer(vector<int>& data)
{
    int n = data.size();

    // Loop over all windows of size buffer_size
    for(int i = 0; i <= n - buffer_size; i++) {
        for(int j = i; j < i + buffer_size; j++) {
            cout << data[j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<int>data = {10,20,30,40,50,60,70,80};
    circular_buffer(data);
    return 0;
}