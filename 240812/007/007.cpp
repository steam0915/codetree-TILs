#include <iostream>
#include <string>

using namespace std;

class C {
public:
  string sc;
  char mt;
  int t;
};

int main() {
  C secret;
  cin >> secret.sc >> secret.mt >> secret.t;
  cout << "secret code : " << secret.sc << endl
       << "meeting point : " << secret.mt << endl
       << "time : " << secret.t;
  return 0;
}