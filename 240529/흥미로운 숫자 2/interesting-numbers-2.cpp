#include <iostream>
#include <string>

using namespace std;

int n, m;
int ans;

bool f(int num) {
  string str = to_string(num);
  int check[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  bool xx = false, yy = false;
  int cnt = 0;

  for (int i = 0; i < str.size(); i++)
    check[str[i] - '0']++;

  for (int i = 0; i < 10; i++) {
    if (check[i] == 1)
      yy = true;
    if (check[i] > 1)
      cnt++;
  }
  if (cnt == 1)
    xx = true;

  return xx && yy;
}

int main() {
  cin >> n >> m;

  for (int i = n; i <= m; i++)
    ans += f(i);

  cout << ans;
  return 0;
}