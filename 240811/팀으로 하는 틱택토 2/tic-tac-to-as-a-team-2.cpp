#include <algorithm>
#include <iostream>

using namespace std;

int ans;
int arr[3][3];
int main() {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      scanf("%1d", &arr[i][j]);

  for (int num1 = 1; num1 <= 9; num1++) {
    for (int num2 = num1 + 1; num2 <= 9; num2++) {

      bool tiktakto = false;

      for (int i = 0; i < 3; i++) {
        int cnt1 = 0;
        for (int j = 0; j < 3; j++)
          if (arr[i][j] == num1 || arr[i][j] == num2)
            cnt1++;

        if (cnt1 == 3 && !(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]))
          tiktakto = true;
      }

      for (int i = 0; i < 3; i++) {
        int cnt2 = 0;
        for (int j = 0; j < 3; j++)
          if (arr[j][i] == num1 || arr[j][i] == num2)
            cnt2++;

        if (cnt2 == 3 && !(arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]))
          tiktakto = true;
      }

      int cnt3 = 0, cnt4 = 0;
      for (int i = 0; i < 3; i++) {
        if (arr[i][i] == num1 || arr[i][i] == num2)
          cnt3++;

        if (arr[2 - i][i] == num1 || arr[2 - i][i] == num2)
          cnt4++;
      }

      if (cnt3 == 3 && !(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]))
        tiktakto = true;

      if (cnt4 == 3 && !(arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2]))
        tiktakto = true;

      if (tiktakto)
        ans++;
    }
  }

  cout << ans;
  return 0;
}