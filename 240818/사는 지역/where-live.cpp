#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class imformation {
public:
  string Name;
  string Address;
  string City;
};
int n;

int main() {
  imformation imf[10];
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> imf[i].Name >> imf[i].Address >> imf[i].City;

  string ans_name = imf[0].Name;
  int ans_idx = 0;

  for (int i = 1; i < n; i++) {
    if (imf[i].Name > ans_name) {
      ans_name = imf[i].Name;
      ans_idx = i;
    }
  }

  cout << "name " << imf[ans_idx].Name << endl
       << "addr " << imf[ans_idx].Address << endl
       << "city " << imf[ans_idx].City;
  return 0;
}