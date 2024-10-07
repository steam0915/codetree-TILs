#include <iostream>

using namespace std;

int arr[105];
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x1,x2;
    cin >> x1>>x2;

    for (int i = x1; i <= x2; i++)
      arr[i]++;
  }

  for (int i = 1; i <= 100; i++)
    if(arr[i] == n) {
      cout<<"Yes";
      return 0;
    }

  cout << "No";
  return 0;
}