#include <iostream>
using namespace std;

int n, r, c;
int arr[205][205];

bool safe(int x, int y) { return 1 <= x && x <= n && 1 <= y && y <= n; }

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> arr[i][j];
  cin >> r >> c;

  for (int dir = 0; dir < 4; dir++) {
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    int x = r, y = c;

    for (int i = 1; i < arr[r][c]; i++) {
      int nx = x + dx[dir], ny = y + dy[dir];
      if (!safe(nx, ny))
        break;

      arr[nx][ny] = 0;
      x = nx, y = ny;
    }
  }
  arr[r][c] = 0;

  for (int y = 1; y <= n; y++) {
    int idx = n;
    int temp_arr[205] = {};

    for (int x = n; x >= 1; x--)
      if (arr[x][y] != 0)
        temp_arr[idx--] = arr[x][y];

    for (int x = 1; x <= n; x++)
      arr[x][y] = temp_arr[x];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      cout << arr[i][j] << " ";
    cout << endl;
  }
  return 0;
}