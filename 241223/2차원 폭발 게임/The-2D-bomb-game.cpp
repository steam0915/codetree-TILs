#include <iostream>

using namespace std;

int n, m, k, ans;
int Grid[105][105];

void Turn() {
  int New_Grid[105][105] = {};

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      New_Grid[j][n - i + 1] = Grid[i][j];

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      Grid[i][j] = New_Grid[i][j];
}

void Drip(int c) {

  int arr[105] = {};
  int idx = n;

  for (int i = n; i >= 1; i--) {
    if (Grid[i][c])
      arr[idx--] = Grid[i][c];
  }

  for (int i = 1; i <= n; i++)
    Grid[i][c] = arr[i];
}

int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> Grid[i][j];

  while (k--) {
    bool Can_Exploison[105][105] = {};
    for (int c = 1; c <= n; c++) {
      for (int r = 1; r <= n - m + 1; r++) {
        bool bomb = true;

        for (int i = 0; i < m - 1; i++)
          if (Grid[r + i][c] != Grid[r + i + 1][c]) {
            bomb = false;
            break;
          }

        if (bomb)
          for (int i = 0; i < m; i++)
            Can_Exploison[r + i][c] = true;
      }
    }

    for (int r = 1; r <= n; r++)
      for (int c = 1; c <= n; c++)
        if (Can_Exploison[r][c])
          Grid[r][c] = 0;

    for (int c = 1; c <= n; c++)
      Drip(c);

    Turn();

    for (int c = 1; c <= n; c++)
      Drip(c);
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (Grid[i][j])
        ans++;

  cout << ans;
  return 0;
}