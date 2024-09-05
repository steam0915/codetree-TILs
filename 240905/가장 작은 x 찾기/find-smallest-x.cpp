#include <iostream>

using namespace std;

int n;
int a[10], b[10];
int main() {
  cin >> n;

  for(int i=0;i<n;i++)
    cin >> a[i] >> b[i];
  
  for (int num = 1; num <= 10000; num++) {
    int st = num;
    bool flag = true;

    for (int i = 0; i < n; i++) {
      st *= 2;
      if (!(a[i] <= st && st <= b[i]))
        flag = false;
    }

    if (flag) {
      cout << num;
      return 0;
    }
  }
  return 0;
}