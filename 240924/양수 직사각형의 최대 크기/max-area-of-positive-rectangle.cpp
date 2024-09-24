#include <algorithm>
#include <iostream>

using namespace std;

int n, m, ans = -1;
int arr[25][25];

bool safe(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }

bool Check_Max_Rect(int x, int y, int x_len, int y_len) {
  for (int i = 0; i <= x_len; i++)
    for (int j = 0; j <= y_len; j++)
      if (arr[x + i][y + j] <= 0)
        return false;

  return true;
}

int Max_Grid(int x, int y) { return (x + 1) * (y + 1); }

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];

  for (int x = 0; x < n; x++)
    for (int y = 0; y < m; y++) {

      for (int x_len = 0; x_len < n; x_len++)
        for (int y_len = 0; y_len < m; y_len++)
          if (safe(x + x_len, y + y_len) && Check_Max_Rect(x, y, x_len, y_len))
            ans = max(ans, Max_Grid(x_len, y_len));

      
    }

  cout << ans;
  return 0;
}