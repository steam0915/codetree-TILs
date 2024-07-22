#include <algorithm>
#include <iostream>

using namespace std;

int n, m, d, s;
int ans;
int arr[55][3];
int sick[55][2];
int main() {
  cin >> n >> m >> d >> s;
  for (int i = 1; i <= d; i++)
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

  for (int i = 1; i <= s; i++)
    cin >> sick[i][0] >> sick[i][1];

  for (int cheese = 1; cheese <= m; cheese++) {
    bool check[55][105];
    for (int i = 1; i <= d; i++) {
      if (arr[i][1] == cheese) {
        for (int t = arr[i][2] + 1; t <= 100; t++)
          check[arr[i][0]][t] = true;
      }
    }
    
    int cnt = 0;
    bool is_wrong = false;
    for (int i = 1; i <= s; i++) {
      if (!check[sick[i][0]][sick[i][1]])
        is_wrong = true;
    }

    if (!is_wrong) {
      for (int i = 1; i <= n; i++)
        if (check[i][100])
          cnt++;
    }

    ans = max(ans, cnt);
  }

  cout << ans;
  return 0;
}