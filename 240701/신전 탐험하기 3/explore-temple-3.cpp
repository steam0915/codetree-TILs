#include <algorithm>
#include <iostream>

#define MAX_N 1000
#define MAX_M 100

using namespace std;

int n, m, ans;
int arr[MAX_N + 1][MAX_M + 1];
int dp[MAX_N + 1][MAX_M + 1];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> arr[i][j];

  for (int j = 1; j <= m; j++)
    dp[1][j] = arr[1][j];

  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      if (dp[i][j] == 0)
        continue;

      for (int k = 1; k <= m; k++)
        if (j != k)
          dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + arr[i + 1][k]);
    }
  }

  for (int j = 1; j <= m; j++)
    ans = max(ans, dp[n][j]);

  cout << ans;
  return 0;
}