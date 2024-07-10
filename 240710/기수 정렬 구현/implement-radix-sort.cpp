#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;

#define MAX_RANGE 100000

void radix_sort() {
  for (int pos = 1; pos <= MAX_RANGE; pos *= 10) {

    vector<int> new_arr[10];

    for (int i = 0; i < (int)arr.size(); i++) {
      int digit = (arr[i] % (pos * 10)) / pos;
      new_arr[digit].push_back(arr[i]);
    }

    vector<int> store_arr;

    for (int i = 0; i < 10; i++)
      for (int j = 0; j < new_arr[i].size(); i++)
        store_arr.push_back(new_arr[i][j]);

    arr = store_arr;
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    arr.push_back(num);
  }

  radix_sort();
  
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  return 0;
}