#include <algorithm>
#include <iostream>

using namespace std;

int n, ans = 0;
int arr[100][2];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i][0] >> arr[i][1];

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        int x1 = arr[i][0], x2 = arr[j][0], x3 = arr[k][0];
        int y1 = arr[i][1], y2 = arr[j][1], y3 = arr[k][1];

        if ((x1 == x2 || x2 == x3 || x3 == x1) &&
            (y1 == y2 || y2 == y3 || y3 == y1)) {
          int area =
              abs((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3));
          ans = max(ans, area);
        }
      }
    }
  }
  cout << ans;
  return 0;
}