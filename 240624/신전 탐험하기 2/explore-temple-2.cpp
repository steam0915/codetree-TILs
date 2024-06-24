#include <algorithm>
#include <iostream>

using namespace std;

int n, ans;
int arr[1001][3];
int dp[3][1001][3];

void Init() {
  dp[0][1][0] = arr[1][0];
  dp[1][1][1] = arr[1][1];
  dp[2][1][2] = arr[1][2];
}

int max3(int a, int b, int c) { return max(a, max(b, c)); }

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

  Init();

  for (int first = 0; first < 3; first++) {
    for (int i = 1; i < n; i++) {

      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          if (j == k || dp[first][i][j] == 0)
            continue;

          dp[first][i + 1][k] =
              max(dp[first][i + 1][k], dp[first][i][j] + arr[i + 1][k]);
        }
      }
    }
  }

  int a0 = 0, a1 = 0, a2 = 0;
  for (int i = 0; i < 3; i++) {

    a0 = max(a0, dp[0][n][i]);
    a1 = max(a1, dp[1][n][i]);
    a2 = max(a2, dp[2][n][i]);
  }

  cout << max3(a0, a1, a2);
  return 0;
}