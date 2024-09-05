#include <algorithm>
#include <iostream>

using namespace std;

int n, k, ans;
int arr[1000];
int main() {
  cin >> n >> k;

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int min_num = 1; min_num <= 10000; min_num++) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
      if (min_num <= arr[i] && arr[i] <= min_num + k)
        cnt++;

    ans = max(ans, cnt);
  }
  cout << ans;
  return 0;
}