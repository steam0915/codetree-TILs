#include <algorithm>
#include <iostream>

#define CHOOSE 1
#define NOT_CHOOSE 0
using namespace std;

int n;
int s[100005], b[100005];
int dp[1001][12][10][2];

void Initialize() {
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= 11; j++)
      for (int k = 0; k <= 9; k++)
        dp[i][j][k][NOT_CHOOSE] = dp[i][j][k][CHOOSE] = -1e9;

  dp[1][1][0][1] = s[1];
  dp[1][0][1][1] = b[1];
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> s[i] >> b[i];

  Initialize();

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 11; j++)
      for (int k = 1; k <= 9; k++) {
        if (j + k > i)
          continue;

        dp[i][j][k][CHOOSE] = max(
            max(dp[i - 1][j - 1][k][NOT_CHOOSE], dp[i - 1][j - 1][k][CHOOSE]) +
                s[i],
            max(dp[i - 1][j][k - 1][NOT_CHOOSE], dp[i - 1][j][k - 1][CHOOSE]) +
                b[i]);

        dp[i][j][k][NOT_CHOOSE] =
            max(dp[i - 1][j][k][NOT_CHOOSE], dp[i - 1][j][k][CHOOSE]);
      }

  cout << max(dp[n][11][9][0], dp[n][11][9][1]);
  return 0;
}