#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

unsigned int n, ans = INT32_MAX;
unsigned int arr[100005];

int main() {
  cin >> n;
  for (int i = 1; i <= 2 * n; i++)
    cin >> arr[i];

  sort(arr + 1, arr + 2 * n + 1);

  for (int i = 1; i <= n; i++)
    ans = min(ans, arr[n + i] - arr[i]);
  cout << ans;
  return 0;
}