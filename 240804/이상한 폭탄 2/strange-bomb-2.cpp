#include <algorithm>
#include <iostream>

using namespace std;

int n, k, ans = -1;
int arr[105];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  for (int i = 1; i <= n; i++) {
    for (int dis = -k; dis <= k; dis++) {
      int idx = i + dis;
      if ((1 <= idx && idx <= n) && dis != 0 && arr[i] == arr[idx])
        ans = max(ans, arr[i]);
    }
  }

  cout << ans;
  return 0;
}