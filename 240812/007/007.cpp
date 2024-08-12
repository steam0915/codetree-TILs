#include <iostream>
#include <string>

using namespace std;

struct S {
  string s_c;
  char m_t;
  int tm;
};

int main() {
  S secret;
  cin >> secret.s_c >> secret.m_t >> secret.tm;
  cout << "secret code : " << secret.s_c << endl
       << "meeting point : " << secret.m_t << endl
       << "time : " << secret.tm;
  return 0;
}