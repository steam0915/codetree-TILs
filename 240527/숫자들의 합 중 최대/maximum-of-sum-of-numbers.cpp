#include <algorithm>
#include <iostream>

using namespace std;
int ans = -1;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = n; i <= m; i++) {
    int sum = 0, num = i;
    while (num != 0) {
      sum = sum + num % 10;
      num /= 10;
    }
    ans = max(ans, sum);
  }
  cout << ans;
  return 0;
}