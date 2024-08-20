#include <algorithm>
#include <iostream>

using namespace std;

class Pos {
public:
  int x;
  int y;
  int num;
};

int n;
Pos pos[1000];

bool cmp(const Pos &a, const Pos &b) {
  if (abs(a.x) + abs(a.y) == abs(b.x) + abs(b.y))
    return a.num < b.num;
  return abs(a.x) + abs(a.y) < abs(b.x) + abs(b.y);
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> pos[i].x >> pos[i].y;
    pos[i].num = i + 1;
  }

  sort(pos, pos + n, cmp);

  for (int i = 0; i < n; i++)
    cout << pos[i].num << endl;
  return 0;
}