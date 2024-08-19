#include <algorithm>
#include <iostream>

using namespace std;

class Data {
public:
  int num;
  int first_pos;
  int last_pos;
};

int n;
Data arr[1000];

bool cmp1(const Data &a, const Data &b) {
  if (a.num == b.num)
    return a.first_pos < b.first_pos;
  return a.num < b.num;
}

bool cmp2(const Data &a, const Data &b) { return a.first_pos < b.first_pos; }

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].num;
    arr[i].first_pos = i + 1;
  }

  sort(arr, arr + n, cmp1);

  for (int i = 0; i < n; i++)
    arr[i].last_pos = i + 1;

  sort(arr, arr + n, cmp2);

  for (int i = 0; i < n; i++)
    cout << arr[i].last_pos << " ";
  return 0;
}