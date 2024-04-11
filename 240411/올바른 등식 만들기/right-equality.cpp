#include <algorithm>
#include <iostream>
#define offset 20
using namespace std;
int n, m;
int arr[105];
long long dp[105][2 * offset + 1];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  for (int i = 0; i <= 2 * offset; i++)
    dp[0][i] = -1;
  dp[0][offset] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 2 * offset - arr[i]; j++) {
      if (dp[i - 1][j] > 0)
        dp[i][j + arr[i]] += dp[i - 1][j];
    }
    for (int j = arr[i]; j <= 2 * offset; j++) {
      if (dp[i - 1][j] > 0)
        dp[i][j - arr[i]] += dp[i - 1][j];
    }
  }
  cout << dp[n][m + offset];
  return 0;
}