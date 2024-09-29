#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

int n, ans = INT_MAX;
int arr[100000];
bool sorted() {
  for (int i = 0; i < n - 1; i++)
    if (arr[i] > arr[i + 1])
      return false;

  return true;
}

int main() {
  cin >> n;
  for (int i = 0; i < 2 * n; i++)
    cin >> arr[i];

  sort(arr,arr+2*n);
  
  for(int i=0;i<n;i++) 
    ans = min(ans,arr[n+i] - arr[i]);

  cout << ans;
  return 0;
}