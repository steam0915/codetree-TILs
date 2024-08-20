#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Data {
public:
  string name;
  int height;
  int weight;
};

Data arr[5];

bool cmp1(const Data &a, const Data &b) {
  return a.name < b.name;
}

bool cmp2(const Data &a, const Data &b) { return a.height > b.height; }

int main() {
  for (int i = 0; i < 5; i++) 
    cin >> arr[i].name >> arr[i].height >> arr[i].weight;

  sort(arr, arr + 5, cmp1);

  for (int i = 0; i < 5; i++)
    cout << arr[i].name << " "<< arr[i].height << " "<<arr[i].weight;

  sort(arr, arr + 5, cmp2);

  for (int i = 0; i < 5; i++)
    cout << arr[i].name << " "<< arr[i].height << " "<<arr[i].weight;
  return 0;
}