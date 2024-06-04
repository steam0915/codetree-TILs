#include <iostream>
#include <string>
using namespace std;

int x, y, ans;
int main() {
  cin >> x >> y;
  for (int i = x; i <= y; i++) {
    string str = to_string(i);

    bool flag = false;
    for (int j = 0; j < str.size() / 2; j++)
      if (str[j] != str[str.size() - 1 - j]) {
        flag = true;
        break;
      }

    if (!flag)
      ans++;
  }
  cout << ans;
  return 0;
}