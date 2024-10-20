#include <iostream>

using namespace std;

int n, m;
int arr[105];
bool End_Time = false;

bool safe(int x) { return 1 <= x && x <= n; }

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  int arr_size = n;

  while (!End_Time) {
    End_Time = true;
    bool explosion[105] = {};

    for (int i = 1; i <= arr_size - m + 1; i++) {
      int num = arr[i];
      bool can_explosion = true;

      for (int j = 1; j < m; j++)
        if (arr[i + j] != num)
          can_explosion = false;

      if (can_explosion) {
        End_Time = false;
        for (int j = 0; j < m; j++)
          explosion[i + j] = true;
      }
    }

    int cnt = 0;
    int temp_arr[105];
    for (int i = 1; i <= arr_size; i++)
      if (explosion[i])
        arr[i] = 0;

    for (int i = 1; i <= arr_size; i++)
      if (arr[i] != 0)
        temp_arr[++cnt] = arr[i];
    arr_size = cnt;
    for (int i = 1; i <= arr_size; i++)
      arr[i] = temp_arr[i];
  }

  cout << arr_size << endl;
  for (int i = 1; i <= arr_size; i++)
    cout << arr[i] << endl;
  return 0;
}