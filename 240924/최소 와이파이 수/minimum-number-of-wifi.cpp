#include <iostream>

using namespace std;

int n, m, cnt;
int arr[100];
bool wifi[100];

bool safe(int x) { return 0 <= x && x < n; }

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 0; i < n; i++) {
    if (arr[i] && !wifi[i]) {
      cnt++;
      for (int j = 0; j <= 2 * m; j++)
        if (safe(i + j))
          wifi[i + j] = true;
    }
  }

  cout << cnt;
  return 0;
}