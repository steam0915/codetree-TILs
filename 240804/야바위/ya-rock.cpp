#include <algorithm>
#include <iostream>

using namespace std;

int n, ans;
int order[100][3];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> order[i][0] >> order[i][1] >> order[i][2];

  for (int stone_pos = 0; stone_pos < 3; stone_pos++) {
    int cnt = 0;
    bool cup[3] = {};
    cup[stone_pos] = true;

    for (int i = 0; i < n; i++) {
      swap(cup[order[i][0]], cup[order[i][1]]);
      if (cup[order[i][2]])
        cnt++;
    }

    ans = max(ans, cnt);
  }
  cout << ans;
  return 0;
}