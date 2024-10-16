#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

void pop(int s, int e) {
  vector<int> temp;
  for (int i = 0; i < v.size(); i++) {
    if (s <= i && i <= e)
      continue;

    temp.push_back(v[i]);
  }

  v = temp;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  int s1, e1, s2, e2;
  cin >> s1 >> e1 >> s2 >> e2;
  s1--, e1--, s2--, e2--;

  pop(s1, e1);
  pop(s2, e2);

  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << endl;

  return 0;
}