#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m, ans;
int dp[205][205];
int value[205];
pair<int, int> days[205];
void Initialize() {
  for (int i = 1; i <= n; i++)
    dp[1][i] = 0;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> days[i].first >> days[i].second >> value[i];

  Initialize();

  for (int i = 2; i <= m; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        if (days[k].first <= i - 1 && i - 1 <= days[k].second &&
            days[j].first <= i && i <= days[j].second)
          dp[i][j] = max(dp[i][j], dp[i - 1][k] + abs(value[j] - value[k]));

  for (int i = 1; i <= n; i++)
    ans = max(ans, dp[m][i]);

  cout << ans;
  return 0;
}