#include <algorithm>
#include <iostream>
using namespace std;

int n, c, g, h;
int ans = -1e9;
int Ta[1005], Tb[1005];

int find_value(int num, int temperature) {
  if (temperature > Tb[num])
    return h;
  else if (temperature >= Ta[num])
    return g;
  else
    return c;
}

int main() {
  cin >> n >> c >> g >> h;

  for (int i = 1; i <= n; i++)
    cin >> Ta[i] >> Tb[i];

  for (int i = 0; i <= 1001; i++) {
    int sum = 0;
    for (int j = 1; j <= n; j++)
      sum += find_value(j, i);

    ans = max(ans, sum);
  }
  cout << ans;
  return 0;
}