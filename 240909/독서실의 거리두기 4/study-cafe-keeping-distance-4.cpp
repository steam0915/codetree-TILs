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
    for (int j = i + 1; j < n; j++) {
      if (!arr[i] && !arr[j]) {
        arr[i] = arr[j] = 1;

        int min_dis = 1e9;
        for (int x1 = 0; x1 < n; x1++)
          for (int x2 = x1 + 1; x2 < n; x2++)
            if (arr[x1] && arr[x2])
              min_dis = min(min_dis, abs(x1 - x2));

        ans = max(ans,min_dis);
        arr[i] = arr[j] = 0;
      }
    }
  }

  cout << ans;
  return 0;
}