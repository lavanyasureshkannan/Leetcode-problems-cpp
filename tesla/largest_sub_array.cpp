
// In the array below, the largest sum subarray starts at index 3 and ends at 6, and with the largest sum being 12.


int find_max_sum_sub_array(int A[], int n) {
  if (n < 1) {
    return 0;
  }
  
  int curr_max = A[0];
  int global_max = A[0];
  for (int i = 1; i < n; ++i) {
    if (curr_max < 0) {
      curr_max = A[i];
    } else {
      curr_max += A[i];
    }

    if (global_max < curr_max) {
      global_max = curr_max;
    }
  }

  return global_max;
}

int main() {
    
    int v[] = {-4, 2, -5, 1, 2, 3, 6, -5, 1};
    cout << "Sum of largest subarray: " << find_max_sum_sub_array(v, sizeof(v) / sizeof(v[0])) << endl;
    return 0;
  }


  // TC: O(N)
  // SC: O(1)