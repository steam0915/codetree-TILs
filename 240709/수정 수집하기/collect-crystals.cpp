#include <algorithm>
#include <iostream>

using namespace std;

int n, k, ans;
int arr[1005];
int dp[1005][25][2];

void Init() {
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= k; j++)
      for (int pos = 0; pos <= 1; pos++)
        dp[i][j][pos] = -1;

  dp[0][0][0] = 0;
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    char dir;
    cin >> dir;
    (dir == 'L') ? arr[i] = 0 : arr[i] = 1;
  }

  Init();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int pos = 0; pos <= 1; pos++) {
        if (dp[i][j][pos] == -1)
          continue;

        if (j < k)
          dp[i + 1][j + 1][!pos] = max(dp[i + 1][j + 1][!pos],
                                       dp[i][j][pos] + ((!pos) == arr[i + 1]));

        dp[i + 1][j][pos] =
            max(dp[i + 1][j][pos], dp[i][j][pos] + (pos == arr[i + 1]));
      }
    }
  }

  for (int i = 0; i <= k; i++)
    for (int j = 0; j <= 1; j++)
      ans = max(ans, dp[n][i][j]);

  cout << ans;
  return 0;
}