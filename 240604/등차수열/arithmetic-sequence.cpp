#include <algorithm>
#include <iostream>

using namespace std;

int ans = -1;
double arr[105];
int max_range = -1, min_range = 101;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (arr[i] > max_range)
      max_range = arr[i];
    if (arr[i] < min_range)
      min_range = arr[i];
  }

  for (int i = min_range; i <= max_range; i++) {
    int cnt = 0;
    for (int j = 1; j < n; j++)
      for (int k = j + 1; k <= n; k++)
        if ((arr[j] + arr[k]) / 2 == i)
          cnt++;
    ans = max(ans, cnt);
  }

  cout << ans;
  return 0;
}