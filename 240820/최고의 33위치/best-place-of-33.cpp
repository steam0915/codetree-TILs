#include <iostream>

using namespace std;

int n, ans;
bool arr[20][20];

bool safe(int x, int y) {
  int x_range = x + 2;
  int y_range = y + 2;

  return 0 <= x_range && x_range < n && 0 <= y_range && y_range < n;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (safe(i, j)) {
        int sum = 0;
        for (int x = 0; x < 3; x++)
          for (int y = 0; y < 3; y++)
            sum += arr[i + x][j + y];

        ans = max(ans, sum);
      }
    }
  }

  cout << ans;
  return 0;
}