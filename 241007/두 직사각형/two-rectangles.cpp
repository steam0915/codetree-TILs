#include <iostream>

using namespace std;

int x1, y1, x2, y2, a1, b1, a2, b2;

bool Overlap() {
  if (x2 < a1)
    return false;

  if (x1 > a2)
    return false;

  if (y1 > b2)
    return false;

  if (y2 < b1)
    return false;

  return true;
}

int main() {
  cin >> x1 >> y1 >> x2 >> y2 >> a1 >> b1 >> a2 >> b2;

  (Overlap()) ? cout << "overlapping" : cout << "nonoverlapping";
  return 0;
}