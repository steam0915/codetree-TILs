#include <iostream>
#include <list>
using namespace std;
int n, m;
list<char> l;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    char a;
    cin >> a;
    l.push_back(a);
  }

  list<char>::iterator it;
  it = l.end();
  for (int i = 1; i <= m; i++) {
    char command;
    cin >> command;

    if (command == 'L')
      it--;

    else if (command == 'R')
      it++;

    else if (command == 'D' && it != l.end())
      it = l.erase(it);

    else if (command == 'P') {
      char a;
      cin >> a;
      l.insert(it, a);
    }
  }
  for (it = l.begin(); it != l.end(); it++)
    cout << *it;
  return 0;
}