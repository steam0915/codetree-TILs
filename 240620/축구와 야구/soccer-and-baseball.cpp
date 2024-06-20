#include <algorithm>
#include <iostream>

#define SOCCER 11
#define BASEBALL 9
using namespace std;

int n;
int s[1005], b[1005];
int dp[1005][15][10];

void Initialize() {
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= SOCCER; j++)
      for (int k = 0; k <= BASEBALL; k++)
        dp[i][j][k] = -1e9;

  for (int i = 0; i <= n; i++)
    dp[i][0][0] = 0;
}

bool safe(int i, int j, int k) {
  return 0 <= i && i <= n && 0 <= j && j <= SOCCER && 0 <= k && k <= BASEBALL;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> s[i] >> b[i];

  Initialize();

  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= SOCCER; j++)
      for (int k = 0; k <= BASEBALL; k++) {
        if (safe(i + 1, j + 1, k))
          dp[i + 1][j + 1][k] =
              max(dp[i + 1][j + 1][k], dp[i][j][k] + s[i + 1]);

        if (safe(i + 1, j, k + 1))
          dp[i + 1][j][k + 1] =
              max(dp[i + 1][j][k + 1], dp[i][j][k] + b[i + 1]);
        if (safe(i + 1, j, k))
          dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
      }

  cout << dp[n][SOCCER][BASEBALL] << endl;

  return 0;
}