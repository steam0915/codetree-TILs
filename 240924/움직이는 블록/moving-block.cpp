#include <iostream>

using namespace std;

int n, tot, avg, ans;
int arr[10000];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 0; i < n; i++)
    tot += arr[i];
  avg = tot / n;

  for (int i = 0; i < n; i++)
    if (arr[i] > avg)
      ans += arr[i] - avg;
  cout << ans;
  return 0;
}