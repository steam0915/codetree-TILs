#include <algorithm>
#include <iostream>

using namespace std;

int n, ans = -1;
int arr[105];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  for (int i = 1; i <= 1000; i++) {
    int start = 1, end = 1, cnt = 0;
    while (end <= n) {

      bool xx = false;
      while (start <= n) {
        if (arr[end] - i > 0) {
          xx = true;
          end++;
        } else
          break;
      }

      if (!xx)
        start++;
      else
        cnt++;

      if (end < start)
        end = start;
    }
    ans = max(ans, cnt);
  }
  cout << ans;
  return 0;
}