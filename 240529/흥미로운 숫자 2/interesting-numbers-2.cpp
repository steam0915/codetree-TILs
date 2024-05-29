#include <iostream>
#include <string>

using namespace std;

int n, m;
int ans;

bool f(int num) {
  string str = to_string(num);
  int check[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  int xx = 0, yy = 0;

  for (int i = 0; i < str.size(); i++)
    check[str[i] - '0']++;

  for (int i = 0; i < 10; i++) {
    if (check[i] == 1)
      yy++;
    if (check[i] > 1)
      xx++;
  }
  if (xx == 1 && yy == 1)
    return true;
  return false;
}

int main() {
  cin >> n >> m;

  for (int i = n; i <= m; i++)
    ans += f(i);

  cout << ans;
  return 0;
}