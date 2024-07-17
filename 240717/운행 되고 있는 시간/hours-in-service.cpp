#include <algorithm>
#include <iostream>

using namespace std;

int n, ans;
int time_table[105][2];
bool max_time[1005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int start, end;
    cin >> start >> end;
    time_table[i][0] = start, time_table[i][1] = end - 1;
  }

  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (i == j)
        continue;

      for (int k = time_table[j][0]; k <= time_table[j][1]; k++)
        max_time[k] = true;
    }
    for (int j = 1; j <= 1000; j++)
      if (max_time[j])
        cnt++;
    for (int j = 1; j <= 1000; j++)
      max_time[j] = false;
    ans = max(ans, cnt);
  }
  cout << ans;
  return 0;
}