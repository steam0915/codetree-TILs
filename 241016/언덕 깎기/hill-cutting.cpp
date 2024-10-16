#include <algorithm>
#include <iostream>

using namespace std;

int n, ans = 1e9;
int arr[1000];

#define Height_Diff 17;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr, arr + n);

  for (int i = 0; i < n; i++) {
    int minh = arr[i];
    int maxh = arr[i] + Height_Diff;
    int maxh_idx;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] >= maxh) {
        maxh_idx = j;
        break;
      }
    }

    int cost = 0;
    for (int j = 0; j < i; j++)
      cost += (arr[i] - arr[j]) * (arr[i] - arr[j]);

    for (int j = maxh_idx; j < n; j++)
      cost += (maxh - arr[j]) * (maxh - arr[j]);

    ans = min(ans, cost);
  }

  cout << ans;
  return 0;
}