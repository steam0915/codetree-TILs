#include <algorithm>
#include <iostream>

#define MAX_N 1000

using namespace std;

int n;
int arr[MAX_N + 1][3];
int dp[3][MAX_N + 1][3];

void Initialize() {
  for (int i = 0; i <= 2; i++)
    dp[i][1][i] = arr[1][i];
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

  Initialize();

  for (int first_floor = 0; first_floor <= 2; first_floor++) {
    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= 2; j++) {

        if (dp[first_floor][i][j] == 0)
          continue;

        for (int k = 0; k <= 2; k++)
          if (j != k)
            dp[first_floor][i + 1][k] =
                max(dp[first_floor][i + 1][k],
                    dp[first_floor][i][j] + arr[i + 1][k]);
      }
    }
  }

  int ls = max(dp[0][n][1], dp[0][n][2]), ms = max(dp[1][n][0], dp[1][n][2]),
      rs = max(dp[2][n][0], dp[2][n][1]);

  (ls < ms)   ? (ms < rs) ? cout << rs : cout << ms
  : (ls < rs) ? cout << rs
              : cout << ls;

  return 0;
}