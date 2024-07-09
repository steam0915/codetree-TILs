#include <algorithm>
#include <iostream>

using namespace std;

int n, ans = 1e9;
int arr[100][2];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i][0] >> arr[i][1];

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int dis = (arr[i][0] - arr[j][0]) * (arr[i][0] - arr[j][0]) +
                (arr[i][1] - arr[j][1]) * (arr[i][1] - arr[j][1]);

      ans = min(ans, dis);
    }
  }
  cout << ans;
  return 0;
}