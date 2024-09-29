#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, k;
pair<int, int> arr[100];
pair<int, int> ans = {0, 2};
bool visit[100];

void Can_Exposed(int idx) {
  if (idx + 1 < n && arr[idx].first == arr[idx + 1].first &&
      arr[idx + 1].second - arr[idx].second <= k)
    visit[idx] = visit[idx + 1] = true;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
  }

  sort(arr, arr + n);

  int i = 0, j = 0;

  while (i < n) {
    int cnt = 0;
    
    while (j < n && arr[i].first == arr[j].first) {
      Can_Exposed(j);
      j++;
    }
    
    for (int x = i; x < j; x++)
      if (visit[x])
        cnt++;

    if (cnt >= ans.second)
      ans = {arr[i].first, cnt};

    i = j;
  }

  cout << ans.first;
  return 0;
}