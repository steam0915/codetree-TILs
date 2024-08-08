#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_N 100

int n, ans = 1e9;
int x[MAX_N], y[MAX_N];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];

  for (int x_line = 2; x_line <= 100; x_line += 2) {
    for (int y_line = 2; y_line <= 100; y_line += 2) {
      int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;

      for (int i = 0; i < n; i++) {
        if (x[i] > x_line && y[i] > y_line)
          cnt1++;

        else if (x[i] < x_line && y[i] > y_line)
          cnt2++;

        else if (x[i] > x_line && y[i] < y_line)
          cnt3++;

        else
          cnt4++;
      }

      ans = min(ans, max(max(cnt1, cnt2), max(cnt3, cnt4)));
    }
  }

  cout << ans;
  return 0;
}