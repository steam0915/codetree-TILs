#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_N 500
#define MAX_M 100
#define MAX_NUM 4

int n, m, ans;
int arr[MAX_N + 1];
int dp[MAX_N + 1][MAX_M + 1][MAX_NUM + 1];

void Init() {
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= m; j++)
      for (int k = 1; k <= MAX_NUM; k++)
        dp[i][j][k] = -1;

  for (int i = 1; i <= 4; i++)
    dp[1][0][i] = (arr[1] == i);
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  Init();

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 1; k <= MAX_NUM; k++) {
        if (dp[i][j][k] == -1)
          continue;

        if (j == m)
          dp[i + 1][j][k] =
              max(dp[i + 1][j][k], dp[i][j][k] + (arr[i + 1] == k));

        else {
          for (int num = 1; num <= MAX_NUM; num++) {
            if (k == num)
              dp[i + 1][j][num] =
                  max(dp[i + 1][j][num], dp[i][j][k] + (arr[i + 1] == num));

            else
              dp[i + 1][j + 1][num] =
                  max(dp[i + 1][j + 1][num], dp[i][j][k] + (arr[i + 1] == num));
          }
        }
      }
    }
  }

  for (int i = 0; i <= m; i++)
    for (int j = 1; j <= MAX_NUM; j++)
      ans = max(ans, dp[n][i][j]);

  cout << ans;
  return 0;
}