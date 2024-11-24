#include <iostream>

using namespace std;

int n, m;
int arr[205][205];

bool safe(int x, int y) { return 1 <= x && x <= n && 1 <= y && y <= n; }

int Find_Top(int c) {
  for (int r = 1; r <= n; r++)
    if (arr[r][c])
      return r;

  return 0;
}

void Explosion(int r, int c) {
  int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

  for (int dir = 0; dir < 4; dir++) {
    for (int i = 1; i < arr[r][c]; i++) {
      int nx = r + dx[dir] * i, ny = c + dy[dir] * i;
      if (safe(nx, ny))
        arr[nx][ny] = 0;
    }
  }
  arr[r][c] = 0;
}

void Drop() {
  for (int c = 1; c <= n; c++) {
    int temp_arr[205] = {};
    int idx = n;

    for (int i = n; i >= 1; i--)
      if (arr[i][c])
        temp_arr[idx--] = arr[i][c];

    for (int i = 1; i <= n; i++)
      arr[i][c] = temp_arr[i];
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> arr[i][j];

  while (m--) {
    int c;
    cin >> c;
    int r = Find_Top(c);

    Explosion(r, c);
    Drop();
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      cout << arr[i][j] << " ";
    cout << endl;
  }
  return 0;
}