#include <iostream>
#define mod 1000000007;
using namespace std;
unsigned long long int n, ans;
long long dp[1005][3][3];
int main() {
  cin >> n;
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++) {
        if (!dp[i][j][k])
          continue;

        dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][k]) % mod;
        if (j < 2)
          dp[i + 1][j + 1][0] = (dp[i + 1][j + 1][0] + dp[i][j][k]) % mod;
        if (k < 2)
          dp[i + 1][j][k + 1] = (dp[i + 1][j][k + 1] + dp[i][j][k]) % mod;
      }

  for (int j = 0; j < 3; j++)
    for (int k = 0; k < 3; k++)
      ans = (ans + dp[n][j][k]) % mod;

  cout << ans;
  return 0;
}