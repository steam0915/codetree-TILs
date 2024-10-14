#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int ans = 1e9;
string str;

bool safe(int x) { return 0 <= x && x < str.length(); }

void str_shift(string &s, int shift_length) {
  string temp_str = str.substr(str.length() - shift_length, shift_length) +
                    str.substr(0, str.length() - shift_length);

  s = temp_str;
}
int main() {
  cin >> str;
  int len = str.length();

  for (int shift_length = 0; shift_length < len; shift_length++) {
    int cnt = 0;
    string s;
    str_shift(s, shift_length);

    int sp = 0, ep = 0;

    while (sp < len) {
      while (safe(ep) && s[sp] == s[ep])
        ep++;

      string num = to_string(ep - sp);
      cnt += num.length();
      cnt++;
      sp = ep;
    }

    ans = min(ans, cnt);
  }
  cout << ans;
  return 0;
}