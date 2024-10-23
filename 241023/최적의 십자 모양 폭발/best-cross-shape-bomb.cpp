#include <algorithm>
#include <iostream>

using namespace std;

int n, cnt, ans = -1e9;
int arr[50][50];
int Grid[50][50];

bool safe(int x, int y) { return 0 <= x && x < n && 0 <= y && y < n; }

void Processing() {
  cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      Grid[i][j] = arr[i][j];
}

void Explosion(int r, int c) {
  int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

  for (int dir = 0; dir < 4; dir++) {
    int x = r, y = c;
    for (int i = 1; i < Grid[r][c]; i++) {
      int nx = x + dx[dir], ny = y + dy[dir];
      if (!safe(nx, ny))
        break;

      Grid[nx][ny] = 0;
      x = nx, y = ny;
    }
  }

  Grid[r][c] = 0;
}

void Drop() {
  for (int y = 0; y < n; y++) {
    int i = n - 1;
    int temp_arr[50] = {};
    for (int x = n - 1; x >= 0; x--)
      if (Grid[x][y])
        temp_arr[i--] = Grid[x][y];

    for (int x = 0; x < n; x++)
      Grid[x][y] = temp_arr[x];
  }
}

void Find_Max() {
  for (int x = 0; x < n; x++)
    for (int y = 0; y < n; y++) {

      int dx[2] = {0, 1}, dy[2] = {1, 0};
      for (int dir = 0; dir < 2; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (safe(nx, ny) && Grid[x][y] && (Grid[x][y] == Grid[nx][ny]))
          cnt++;
      }
    }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];

  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      Processing();
      Explosion(x, y);
      Drop();
      Find_Max();

      ans = max(ans, cnt);
    }
  }

  cout << ans;
  return 0;
}