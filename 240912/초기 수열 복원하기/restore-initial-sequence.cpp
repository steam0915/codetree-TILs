#include <iostream>

using namespace std;

#define MAX_N 1000

int n;
int sum_arr[MAX_N];
int arr[MAX_N];
bool visit[MAX_N + 1];
void f(int idx) {
  if (idx >= n) {
    for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
    exit(0);
  }

  for (int i = 1; i <= n; i++) {
    if (sum_arr[idx] == i + arr[idx - 1] && !visit[i]) {
      visit[i] = true;
      arr[idx] = i;

      f(idx + 1);
      
      visit[i] = false;
      arr[idx] = 0;
    }
  }
}

int main() {
  cin >> n;
  for (int i = 1; i < n; i++)
    cin >> sum_arr[i];

  for (int i = 1; i <= n; i++) {
    visit[i] = true;
    arr[0] = i;

    f(1);

    visit[i] = false;
    arr[0] = 0;
  }

  return 0;
}