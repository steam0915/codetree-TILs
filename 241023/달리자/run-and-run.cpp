#include <algorithm>
#include <iostream>

using namespace std;

int n, dis;
int before[105], after[105], dif[105];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> before[i];
  for (int i = 1; i <= n; i++)
    cin >> after[i];

  for (int i = 1; i <= n; i++)
    dif[i] = before[i] - after[i];

  for (int i = 1; i <= n; i++) 
    for (int j = i + 1; j <= n; j++) {
      if (dif[i] > 0 && dif[j] < 0) {
        if (dif[i] <= abs(dif[j])) {
          dis += abs(i - j) * dif[i];
          dif[j] += dif[i];
          dif[i] = 0;
        }

        else {
          dis += abs(i - j) * dif[j];
          dif[i] += dif[j];
          dif[j] = 0;
        }
      }
    }
  

  cout << dis;
  return 0;
}