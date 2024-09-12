#include <algorithm>
#include <iostream>

using namespace std;

int n, k, ans_num, ans_cnt;
int arr[105];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  for (int bomb_num = 0; bomb_num <= 1000000; bomb_num++) {
    bool visit[105] = {};
    for (int i = 1; i <= n; i++) {
      for (int dis = -k; dis <= k; dis++) {
        int idx = i + dis;
        if ((1 <= idx && idx <= n) && arr[i] == bomb_num && arr[i] == arr[idx])
          visit[i] = visit[idx] = true;
      }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
      if (visit[i])
        cnt++;

    if (ans_cnt <= cnt) {
      ans_cnt = cnt;
      ans_num = bomb_num;
    }
  }

  cout << ans_num;
  return 0;
}