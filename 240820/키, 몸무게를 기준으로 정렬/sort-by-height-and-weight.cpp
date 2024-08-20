#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Data {
public:
  string name;
  int height;
  double weight;
};

int n;
Data arr[10];

bool cmp(const Data &a, const Data &b) {
  if (a.height == b.height)
    return a.weight > b.weight;
  return a.height < b.height;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i].name >> arr[i].height >> arr[i].weight;

  sort(arr, arr + 5, cmp);
  for (int i = 0; i < n; i++)
    cout << arr[i].name << " " << arr[i].height << " " << arr[i].weight << endl;
  
  return 0;
}