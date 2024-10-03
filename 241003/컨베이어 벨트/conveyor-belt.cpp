#include <iostream>

using namespace std;

int n, t;
int arr[2][200];
int main() {
  cin >> n >> t;
  for (int i = 0; i < n; i++)
    cin >> arr[0][i];

  for (int i = 0; i < n; i++)
    cin >> arr[1][n - 1 - i];

  for (int time = 0; time < t; time++) {
    int temp1 = arr[0][n - 1];
    int temp2 = arr[1][0];

    for (int i = n - 2; i >= 0; i--)
      arr[0][i + 1] = arr[0][i];

    for (int i = 0; i <= n - 2; i++)
      arr[1][i] = arr[1][i + 1];

    arr[0][0] = temp2;
    arr[1][n - 1] = temp1;
  }

  for (int i = 0; i < n; i++)
    cout << arr[0][i] << " ";
  cout << endl;

  for (int i = 0; i < n; i++)
    cout << arr[1][n - 1 - i] << " ";
  return 0;
}