#include <algorithm>
#include <iostream>

using namespace std;

int n, k, ans, ans_num;
int arr[100];
int main() {
  cin >> n >> k;

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int num = 0; num <= 1000000; num++) {
    int cnt = 0;
    bool visit[100] = {};

    for (int i = 0; i < n; i++) {
      if (arr[i] == num) {
        visit[i] = true;
        for (int j = 1; j <= k; j++) {
          if (i + j < n && arr[i + j] == arr[i])
            visit[i + j] = true;
        }
      }
    }

    for (int i = 0; i < n; i++)
      if (visit[i])
        cnt++;

    if (cnt > ans_num) {
      ans_num = cnt;
      ans = num;
    }
  }

  cout << ans;
  return 0;
}