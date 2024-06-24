#include <algorithm>
#include <iostream>

#define MOD 10000000007

using namespace std;

int n;
unsigned int dp[1005][10];
unsigned int ans;

void Initialize() {
  for (int i = 0; i < 10; i++)
    dp[1][i] = 1;
}

int main() {
  cin >> n;

  Initialize();

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= 9; j++) {
      if (j == 0)
        dp[i][j] = dp[i - 1][1] % MOD;

      else if (j == 9)
        dp[i][j] = dp[i - 1][8] % MOD;

      else
        dp[i][j] = (dp[i - 1][j - 1] % MOD + dp[i - 1][j + 1] % MOD) % MOD;
    }
  }

  for (int i = 1; i <= 9; i++)
    ans = (ans % MOD + dp[n][i] % MOD) % MOD;

  cout << ans;
  return 0;
}