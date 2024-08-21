#include <algorithm>
#include <iostream>

using namespace std;

int n, ans;
int arr[20];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    scanf("%1d", &arr[i]);

  for (int i = 0; i < n; i++) {
    if (arr[i])
      continue;
    int min_dis = 1e9;
    for (int j = 0; j < n; j++) {
      if (arr[j])
        min_dis = min(min_dis, abs(i - j));
    }

    ans = max(ans, min_dis);
  }

  cout << ans;
  return 0;
}