#include <algorithm>
#include <iostream>

using namespace std;

int n, b, ans;
int p[1005];

int main() {
  cin >> n >> b;
  for (int i = 1; i <= n; i++)
    cin >> p[i];

  for (int i = 1; i <= n; i++) {
    p[i] /= 2;

    int sum = 0, cnt = 0;
    int new_p[1005];
    for (int j = 1; j <= n; j++)
      new_p[j] = p[j];
    sort(new_p + 1, new_p + n + 1);

    for (int j = 1; j <= n; j++) {
      if (sum + new_p[j] <= b) {
        sum += new_p[j];
        cnt++;
      }
    }
    ans = max(ans, cnt);
    p[i] *= 2;
  }

  cout << ans;
  return 0;
}