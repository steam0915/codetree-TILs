#include <iostream>

using namespace std;

int n,ans;
int arr[100];
bool sorted() {
  for(int i=0;i<n-1;i++)
    if(arr[i] > arr[i+1])
      return false;

  return true;
}

int main() {
  cin >> n;
  for(int i=0;i<n;i++) {
    cin >> arr[i];
    if(arr[i] == n)ans = i+1;
  }

  cout << ans;
  return 0;
}