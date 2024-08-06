#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100

int n;
int arr[MAX_N][MAX_N];
pair<int, int> dp[MAX_N][MAX_N];

void Init() {
  dp[1][1] = {arr[1][1], arr[1][1]};

  for (int i = 1; i <= n; i++) {
    dp[0][i] = {-1e9, 1e9};
    dp[i][0] = {-1e9, 1e9};
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> arr[i][j];

  Init();

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == 1 && j == 1)
        continue;

      pair<int, int> left, up;

      if (dp[i][j - 1].first > arr[i][j]) {
        left.first = arr[i][j];
        left.second = dp[i][j - 1].second;
      }

      else if (dp[i][j - 1].second < arr[i][j]) {
        left.first = dp[i][j - 1].first;
        left.second = arr[i][j];
      }

      else
        left = dp[i][j - 1];

      if (dp[i - 1][j].first > arr[i][j]) {
        up.first = arr[i][j];
        up.second = dp[i - 1][j].second;
      }

      else if (dp[i - 1][j].second < arr[i][j]) {
        up.first = dp[i - 1][j].first;
        up.second = arr[i][j];
      }

      else
        up = dp[i - 1][j];

      int left_diff = abs(left.first - left.second),
          up_diff = abs(up.first - up.second);

      (left_diff > up_diff) ? dp[i][j] = up : dp[i][j] = left;
    }
  }
  
  cout << abs(dp[n][n].first - dp[n][n].second);
  return 0;
}