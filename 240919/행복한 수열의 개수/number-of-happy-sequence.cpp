#include <iostream>
#include <vector>

using namespace std;

int n, m, ans;
int arr[105][105];

bool Is_Same(vector<int> v, int start_point) {
  for (int i = 0; i < m - 1; i++)
    if (v[start_point + i] != v[start_point + i + 1])
      return false;

  return true;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];

  for (int i = 0; i < n; i++) {
    vector<int> v;

    for (int j = 0; j < n; j++)
      v.push_back(arr[i][j]);

    for (int j = 0; j < n - m + 1; j++)
      if (Is_Same(v, j)) {
        ans++;
        break;
      }
  }

  for (int i = 0; i < n; i++) {
    vector<int> v;

    for (int j = 0; j < n; j++)
      v.push_back(arr[j][i]);

    for (int j = 0; j < n - m + 1; j++)
      if (Is_Same(v, j)) {
        ans++;
        break;
      }
  }

  cout << ans;
  return 0;
}