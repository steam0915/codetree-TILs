#include <iostream>

using namespace std;

int n, cnt;
int arr[15] = {0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int bird_num, state;
    cin >> bird_num >> state;

    if (arr[bird_num] == -1)
      arr[bird_num] = state;

    else if (arr[bird_num] != state) {
      arr[bird_num] = state;
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}