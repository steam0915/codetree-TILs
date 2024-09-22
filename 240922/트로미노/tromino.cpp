#include <algorithm>
#include <iostream>

using namespace std;

int n, m, ans;
int arr[205][205];

bool safe(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }

int Make_Sum(int x1, int y1, int x2, int y2, int x3, int y3) {
  return arr[x1][y1] + arr[x2][y2] + arr[x3][y3];
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x = i, y = j;

      int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
      for (int dir = 0; dir < 4; dir++) {
        int nx1 = x + dx[dir % 4], ny1 = y + dy[dir % 4];
        int nx2 = x + dx[(dir + 1) % 4], ny2 = y + dy[(dir + 1) % 4];

        if (safe(nx1, ny1) && safe(nx2, ny2))
          ans = max(ans, Make_Sum(x, y, nx1, ny1, nx2, ny2));
      }

      if (safe(x, y + 1) && safe(x, y + 2))
        ans = max(ans, Make_Sum(x, y, x, y + 1, x, y + 2));

      if (safe(x + 1, y) && safe(x + 2, y))
        ans = max(ans, Make_Sum(x, y, x + 1, y, x + 2, y));
    }
  }

  cout << ans;
  return 0;
}