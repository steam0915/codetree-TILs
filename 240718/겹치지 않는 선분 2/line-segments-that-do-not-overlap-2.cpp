#include <algorithm>
#include <iostream>

using namespace std;

int n, ans;
int x1[105], x2[105];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> x1[i] >> x2[i];

  for (int i = 1; i <= n; i++) {
    int x11 = x1[i], x12 = x2[i];
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (i == j)
        continue;

      int x21 = x1[j], x22 = x2[j];

      if ((x11 - x21) * (x12 - x22) < 0)
        cnt++;
    }

    if (cnt == 0)
      ans++;
  }
  cout << ans;
  return 0;
}