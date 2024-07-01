#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, ans = INT_MAX;
pair<int, int> arr[105];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> arr[i].first >> arr[i].second;

  for (int i = 1; i <= n; i++) {
    int max_x = 0, min_x = 40001, max_y = 0, min_y = 40001;
    for (int j = 1; j <= n; j++) {
      if (i == j)
        continue;

      max_x = max(max_x, arr[j].first), min_x = min(min_x, arr[j].first),
      max_y = max(max_y, arr[j].second), min_y = min(min_y, arr[j].second);
    }
    ans = min(ans, (max_x - min_x) * (max_y - min_y));
  }

  cout << ans;
  return 0;
}