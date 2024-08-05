#include <algorithm>
#include <iostream>

using namespace std;

int a, b, c, ans;
int main() {
  cin >> a >> b >> c;

  for (int i = 0;; i++) {
    if (a * i > c)
      break;
    for (int j = 0;; j++) {
      if (a * i + b * j <= c)
        ans = max(ans, a * i + b * j);
      else
        break;
    }
  }
  cout << ans;
  return 0;
}