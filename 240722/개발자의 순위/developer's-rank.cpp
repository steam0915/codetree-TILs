#include <algorithm>
#include <iostream>

using namespace std;

int k, n, cnt;
int arr[10][20];
int main() {
  cin >> k >> n;
  for (int i = 0; i < k; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];

  for (int a = 0; a < n; a++) {
    for (int b = 0; b < n; b++) {
      if (a == b)
        continue;

      bool flag = true;
      for (int i = 0; i < k; i++) {
        int a_score, b_score;
        for (int j = 0; j < n; j++) {
          if (arr[i][j] == a + 1)
            a_score = n - j;
          if (arr[i][j] == b + 1)
            b_score = n - j;
        }

        if (!(a_score > b_score))
          flag = false;
      }

      if (flag) 
        cnt++;
        
    }
  }
  cout << cnt;
  return 0;
}