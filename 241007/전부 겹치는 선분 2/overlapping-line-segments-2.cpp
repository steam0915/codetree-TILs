#include <iostream>

using namespace std;

int n;
int arr[105], pos[105][2];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> pos[i][0] >> pos[i][1];

    for (int j = pos[i][0]; j <= pos[i][1]; j++)
      arr[j]++;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = pos[i][0]; j <= pos[i][1]; j++)
      arr[i]--;

    for (int j = 1; j <= 100; j++)
      if (arr[j] == n - 1) {
        cout << "Yes";
        return 0;
      }

    for (int j = pos[i][0]; j <= pos[i][1]; j++)
      arr[i]++;
  }

  cout << "No";
  return 0;
}