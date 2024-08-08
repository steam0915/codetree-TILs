#include <algorithm>
#include <iostream>

using namespace std;

int n, m, ans = -1e9;
int arr[105];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  for (int i = 1; i <= n; i++) {
    int point = i;
    int sum = 0;
    for (int j = 1; j <= m; j++) {
      sum += arr[point];
      point = arr[point];
    }

    ans = max(ans, sum);
  }

  cout << ans;
  return 0;
}