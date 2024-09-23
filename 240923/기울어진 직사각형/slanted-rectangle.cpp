#include <algorithm>
#include <iostream>

using namespace std;

int n, ans;
int arr[25][25];

bool safe(int x, int y) { return 0 <= x && x < n && 0 <= y && y < n; }

int Make_Diagram(int x, int y, int l1, int l2) {
  int sum = 0;
  int dx[4] = {-1, -1, 1, 1}, dy[4]{1, -1, -1, 1};

  for (int dir = 0; dir < 4; dir++) {
    if (dir % 2 == 0) {
      for (int i = 1; i <= l1; i++) {
        x = x + dx[dir], y = y + dy[dir];

        if (safe(x, y))
          sum += arr[x][y];
        else
          return 0;
      }
    }

    else {
      for (int i = 1; i <= l2; i++) {
        x = x + dx[dir], y = y + dy[dir];

        if (safe(x, y))
          sum += arr[x][y];
        else
          return 0;
      }
    }
  }

  return sum;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int len1 = 1; len1 <= n; len1++)
        for (int len2 = 1; len2 <= n; len2++)
          ans = max(ans, Make_Diagram(i, j, len1, len2));

  cout << ans;
  return 0;
}