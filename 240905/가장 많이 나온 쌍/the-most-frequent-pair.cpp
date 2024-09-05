#include <algorithm>
#include <iostream>

using namespace std;

int n, m, ans;
int a[100], b[100];
int main() {
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    a[i] = min(x, y), b[i] = max(x, y);
  }

  for (int num1 = 1; num1 <= 10; num1++) {
    for (int num2 = num1 + 1; num2 <= 10; num2++) {

      int cnt = 0;
      for (int i = 0; i < m; i++)
        if (a[i] == num1 && b[i] == num2)
          cnt++;

      ans = max(ans, cnt);
    }
  }
  cout << ans;
  return 0;
}