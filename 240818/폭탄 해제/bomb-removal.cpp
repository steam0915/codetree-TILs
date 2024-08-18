#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Bomb {
public:
  string Code;
  char Color;
  int sec;
};

int main() {
  Bomb bomb;
  cin >> bomb.Code >> bomb.Color >> bomb.sec;
  cout << "code : " << bomb.Code << endl
       << "color : " << bomb.Color << endl
       << "second : " << bomb.sec;
  return 0;
}