#include <iostream>

using namespace std;

int n;
int even_cnt, odd_cnt;
int arr[1000];

bool sat() { return even_cnt - odd_cnt == 1 || even_cnt - odd_cnt == 0; }

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] % 2 == 0)
      even_cnt++;
    else
      odd_cnt++;
  }

  while (even_cnt < odd_cnt) {
    even_cnt += 1;
    odd_cnt -= 2;
  }

  while (!sat())
    even_cnt--;

  cout << even_cnt + odd_cnt;
  return 0;
}