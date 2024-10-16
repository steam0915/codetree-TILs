#include <algorithm>
#include <iostream>

using namespace std;

int n, ans = 1e9;
int arr[1000];

#define Max_Height 100
#define Height_Diff 17

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr, arr + n);

  for (int i = 0; i <= Max_Height - Height_Diff; i++) {
    int minh_idx = 0, maxh_idx = n - 1;
    int cost = 0;

    while (arr[minh_idx] <= i)
      minh_idx++;

    while (arr[maxh_idx] >= i + Height_Diff)
      maxh_idx--;

    for (int j = 0; j < minh_idx; j++)
      cost += (i - arr[j]) * (i - arr[j]);

    for (int j = maxh_idx + 1; j < n; j++)
      cost += (i + Height_Diff - arr[j]) * (i + Height_Diff - arr[j]);

    ans = min(ans, cost);
  }

  cout << ans;
  return 0;
}