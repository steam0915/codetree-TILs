#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_N 1000

int n, b, ans;
int p[MAX_N], s[MAX_N];
int main() {
  cin >> n >> b;
  for (int i = 0; i < n; i++)
    cin >> p[i] >> s[i];

  for (int i = 0; i < n; i++) {
    int sum_price[MAX_N] = {};
    p[i] /= 2;

    for (int j = 0; j < n; j++)
      sum_price[j] = p[i] + s[i];
    sort(sum_price, sum_price + n);
    int budget = 0;
    for (int j = 0; j < n; j++) {
      budget += sum_price[j];
      if (budget > b) {
        ans = max(ans, j);
        break;
      }
    }

    p[i] *= 2;
  }
  cout << ans;
  return 0;
}