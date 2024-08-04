#include <algorithm>
#include <iostream>

using namespace std;

int n, k, cnt;
int arr[10][2];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i][0] >> arr[i][1];

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        
        int line[101] = {};
        for (int l = 0; l < n; l++) {
          if (l == i || l == j || l == k)
            continue;

          for (int chk_idx = arr[l][0]; chk_idx <= arr[l][1]; chk_idx++)
            line[chk_idx]++;
        }
        
        bool sat = true;
        for (int l = 0; l <= 100; l++)
          if (line[l] > 1)
            sat = false;

        if (sat)
          cnt++;
      }
    }
  }

  cout << cnt;
  return 0;
}