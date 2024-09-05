#include <algorithm>
#include <iostream>

using namespace std;

int n, k, ans;
int arr[100];
int dp[100];
int main() {
  cin >> n >> k;

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 0; i < n; i++)
    dp[i] = 1e9;
  dp[0] = arr[0];

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      if (i + j < n)
        dp[i + j] = min(dp[i + j], max(dp[i], arr[i + j]));
    }
  }
  cout << dp[n - 1];
  return 0;
}