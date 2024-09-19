#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, k, ans_num, ans_cnt;
int arr[105];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  for (int bomb_num = 0; bomb_num <= 1000000; bomb_num++) {
    vector<int> v;
    int cnt = 0;

    for (int i = 1; i <= n; i++)
      if (arr[i] == bomb_num)
        v.push_back(i);

    for (int i = 0; i < (int)v.size() - 1; i++)
      if (abs(arr[v[i]] - arr[v[i + 1]]) <= k)
        cnt++;

    if (cnt != 0 && cnt >= ans_cnt) {
      ans_cnt = cnt;
      ans_num = bomb_num;
    } 
  }

  cout << ans_num;
  return 0;
}