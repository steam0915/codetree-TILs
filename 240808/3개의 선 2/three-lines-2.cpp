#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_N 20

int n, ans;
int x[MAX_N], y[MAX_N];
int def_xy[3];

void f() {
  for (int i = 0; i <= 10; i++)
    for (int j = 0; j <= 10; j++)
      for (int k = 0; k <= 10; k++) {
        
        bool check[MAX_N] = {};

        for (int xy = 0; xy < 3; xy++) {

          int num;
          if (xy == 0)
            num = i;
          else if (xy == 1)
            num = j;
          else
            num = k;

          for (int idx = 0; idx < n; idx++) {
            if ((def_xy[xy] == 1 && x[idx] == num) ||
                (def_xy[xy] == 2 && y[idx] == num))
              check[idx] = true;
          }
        }

        bool flag;
        for (int idx = 0; idx < n; idx++)
          flag = check[idx];

        if (flag) {
          ans = true;
          return;
        }
      }
}

void choose_xy(int idx) {
  if (idx > 2) {
    f();
    return;
  }

  def_xy[idx] = 1;
  choose_xy(idx + 1);
  def_xy[idx] = 0;

  def_xy[idx] = 2;
  choose_xy(idx + 1);
  def_xy[idx] = 0;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i];

  choose_xy(0);

  cout << ans;
  return 0;
}