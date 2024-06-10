#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
int arr[505];
int dp[505][255][2];

void Initialize() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int k = 0; k <= 1; k++)
        dp[i][j][k] = -1e9;

  dp[1][1][1] = arr[1];
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  Initialize();

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k <= 1; k++) {
        if ((i + k) / 2 < j)
          continue;
        if (k == 0) {
          for (int l = 0; l < 2; l++) {
            if (dp[i - 1][j][l] == -1e9)
              continue;

            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][l]);
          }
        }

        else {
          int dy[2] = {0, -1}, z[2] = {1, 0};
          for (int l = 0; l < 2; l++) {
            if (dp[i - 1][j + dy[l]][z[l]] == -1e9)
              continue;

            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j + dy[l]][z[l]] + arr[i]);
          }
        }
      }
    }
  }
  cout << max(dp[n][m][0],dp[n][m][1]);

  return 0;
}