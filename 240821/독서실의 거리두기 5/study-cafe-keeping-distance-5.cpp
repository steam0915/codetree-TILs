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

    arr[i] = 1;
    int min_dis = 1e9;
    for (int j = 0; j < n; j++)
      for (int k = j + 1; k < n; k++)
        if (arr[k] && arr[j])
          min_dis = min(min_dis, abs(j - k));

    ans = max(ans, min_dis);
    arr[i] = 0;
  }

  cout << ans;
  return 0;
}