#include <iostream>

using namespace std;

bool arr[105];
int a, b, c, d;
int cnt;
int main() {
  cin >> a >> b >> c >> d;
  for (int i = a; i < b; i++)
    arr[i] = true;

  for (int i = c; i < d; i++)
    arr[i] = true;

  for (int i = 0; i <= 100; i++)
    cnt += arr[i];

  cout << cnt;
  return 0;
}