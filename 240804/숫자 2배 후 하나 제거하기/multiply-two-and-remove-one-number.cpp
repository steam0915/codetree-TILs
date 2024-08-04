#include <algorithm>
#include <iostream>

using namespace std;

int n, ans = 1e9;
int arr[100];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 0; i < n; i++) {
    arr[i] *= 2;

    for (int j = 0; j < n; j++) {
      int idx = 0;
      int new_arr[100] = {};

      for (int k = 0; k < n; k++) 
        if (k != j)
          new_arr[idx++] = arr[k];
      
      int sum_diff = 0;
      for (int k = 0; k < n - 2; k++) {
        sum_diff += abs(new_arr[k] - new_arr[k + 1]);
      }

      ans = min(ans, sum_diff);
    }

    arr[i] /= 2;
  }
  cout << ans;
  return 0;
}