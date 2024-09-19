#include <iostream>
#include <vector>

using namespace std;

int n, m, ans;
int arr[105][105];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];

  for (int i = 0; i < n; i++) {
    vector<int> v;

    for (int j = 0; j < n; j++)
      v.push_back(arr[i][j]);

    for (int j = 0; j < n - m + 1; j++) {
      bool Same = true;
      for (int k = 0; k < m - 1; k++)
        if (v[j + k] != v[j + k + 1])
          Same = false;

      if (Same) {
        ans++;
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    vector<int> v;
    bool Same = true;

    for (int j = 0; j < n; j++)
      v.push_back(arr[j][i]);

    for (int j = 0; j < n - m + 1; j++) {
      for (int k = 0; k < m - 1; k++)
        if (v[j + k] != v[j + k + 1])
          Same = false;

      if (Same) {
        ans++;
        break;
      }
    }
  }

  cout << ans;
  return 0;
}