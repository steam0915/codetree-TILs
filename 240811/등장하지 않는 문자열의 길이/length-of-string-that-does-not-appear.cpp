#include <iostream>
#include <string>

using namespace std;

int n;
string str;
int main() {
  cin >> n;
  cin >> str;

  for (int len = 1; len <= n; len++) {
    for (int i = 0; i < n - len + 1; i++) {
      
      int cnt = 0;
      string min_str = str.substr(i, len);
      
      for (int j = 0; j < n - len + 1; j++) {
        string s = str.substr(j, len);
        if (min_str == s)
          cnt++;    
      }
      if (cnt >= 2)
        break;

      else {
        cout << len;
        return 0;
      }
    }
  }
  return 0;
}