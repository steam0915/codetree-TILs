#include <algorithm>
#include <iostream>
#define MAX_DIS 1000;

using namespace std;

int t, a, b;
int ans;
char dir[1005];
bool pos[1005];
int main() {
  cin >> t >> a >> b;

  for (int i = 1; i <= t; i++) {
    char d;
    int p;
    cin >> d >> p;
    pos[p] = true;
    dir[p] = d;
  }

  for (int i = a; i <= b; i++) {
    int s_dis = MAX_DIS;
    int n_dis = MAX_DIS;

    for (int j = 1; j <= 1000; j++)
      if (dir[j] == 'S' && abs(i - j) < s_dis)
        s_dis = abs(i - j);

    for (int j = 1; j <= 1000; j++)
      if (dir[j] == 'N' && abs(i - j) < n_dis)
        n_dis = abs(i - j);

    if (s_dis <= n_dis)
      ans++;
  }
  cout << ans;
  return 0;
}