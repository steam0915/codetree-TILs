#include <algorithm>
#include <iostream>

using namespace std;

int n, ans;
int arr[1005][5];
int dp[1005][5];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> arr[i][1] >> arr[i][2] >> arr[i][3];

  for (int i = 1; i <= n; i++) {

    for (int j = 1; j <= 3; j++) {
      for (int k = 1; k <= 3; k++) {
        if (j == k)
          continue;

        dp[i][j] = max(dp[i][j], dp[i - 1][k] + arr[i][j]);
      }
    }
  }
  for (int i = 1; i <= 3; i++)
    ans = max(ans, dp[n][i]);

  cout << ans;
  return 0;
}