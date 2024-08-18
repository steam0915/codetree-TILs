#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Product {
public:
  string Name;
  int Code;
};

int main() {
  Product pd1, pd2;
  pd1 = {"codetree", 50};
  cin >> pd2.Name >> pd2.Code;
  cout << "product " << pd1.Code << " is " << pd1.Name << endl
       << "product " << pd2.Code << " is " << pd2.Name;
  return 0;
}