#include <algorithm>
#include <iostream>

using namespace std;

int k, n, cnt;
int arr[10][20];
int main() {
  cin >> k >> n;
  for (int i = 0; i < k; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];

  for (int a = 0; a < n; a++) {
    for (int b = 0; b < n; b++) {
      if (a == b)
        continue;

      bool flag = true;
      for (int i = 0; i < k; i++) {
        if (!(arr[i][a] > arr[i][b]))
          flag = false;
      }

      if (flag)
        cnt++;
    }
  }
  cout << cnt;
  return 0;
}