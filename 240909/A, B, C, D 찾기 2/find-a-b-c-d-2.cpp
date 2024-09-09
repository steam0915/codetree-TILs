#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<int> cmp;
int num[4];

void f(int idx, int sum) {
  if (idx > 3) {
    if (sum == 0)
      return;
    else {
      cmp.push_back(sum);
      return;
    }
  }

  f(idx + 1, sum);

  f(idx + 1, sum + num[idx]);
}

bool checking() {
  f(0, 0);
  sort(cmp.begin(), cmp.end());

  if (cmp == arr)
    return true;

  return false;
}

int main() {
  for (int i = 0; i < 15; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  sort(arr.begin(), arr.end());

  for (int a = 1; a <= 40; a++)
    for (int b = a; b <= 40; b++)
      for (int c = b; c <= 40; c++)
        for (int d = c; d <= 40; d++) {
          num[0] = a;
          num[1] = b;
          num[2] = c;
          num[3] = d;

          if (checking()) {
            cout << a << " " << b << " " << c << " " << d;
            return 0;
          }

          while (!cmp.empty())
            cmp.pop_back();
        }

  return 0;
}