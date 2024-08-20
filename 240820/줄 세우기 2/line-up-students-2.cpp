#include <algorithm>
#include <iostream>

using namespace std;

class Student {
public:
  int h;
  int w;
  int num;
};

int n;
Student students[1000];

bool cmp(const Student &a, const Student &b) {
  if (a.h == b.h)
    return a.w > b.w;
  return a.h < b.h;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> students[i].h >> students[i].w;
    students[i].num = i + 1;
  }

  sort(students, students + n, cmp);

  for (int i = 0; i < n; i++)
    cout << students[i].h << " " << students[i].w << " " << students[i].num
         << endl;
  return 0;
}