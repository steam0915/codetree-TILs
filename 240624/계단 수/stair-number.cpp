#include <algorithm>
#include <iostream>

#define MOD 1000000007

using namespace std;

int n;
long long int dp[1005][10];
long long int ans;

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
        dp[i][j] = dp[i - 1][1];

      else if (j == 9)
        dp[i][j] = dp[i - 1][8];

      else
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
    }
  }

  for (int i = 1; i <= 9; i++)
    ans =  (ans + dp[n][i]) % MOD;

  cout << ans % MOD;
  return 0;
}