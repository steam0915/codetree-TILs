#include <algorithm>
#include <iostream>

using namespace std;

int n, k, ans;
int arr[100];
int main() {
  cin >> n >> k;

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int num = 0; num <= 1000000; num++) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] == num) {
        for (int j = 1; j <= k; j++) {
          if (i + j < n && arr[i + j] == arr[i]) {
            cnt++;
            break;
          }
        }
      }
    }
    ans = max(ans, cnt);
  }

  cout << ans;
  return 0;
}