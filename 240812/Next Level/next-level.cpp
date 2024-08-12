#include <iostream>
#include <string>

using namespace std;

class imf {
public:
  string id;
  int lv;
};

int main() {
  imf user;
  cin >> user.id >> user.lv;
  imf user1 = {"codetree", 10};
  imf user2 = user;

  cout << "user " << user1.id << " lv " << user1.lv << endl;
  cout << "user " << user2.id << " lv " << user2.lv;
  return 0;
}