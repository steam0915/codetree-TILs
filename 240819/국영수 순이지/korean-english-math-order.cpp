#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Student {
public:
  string name;
  int kor;
  int eng;
  int math;
};

int n;
Student students[10];

bool cmp(const Student &a, const Student &b) {
  if (a.kor == b.kor) {
    if (a.eng == b.eng)
      return a.math > b.math;
    return a.eng > b.eng;
  }
  return a.kor > b.kor;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> students[i].name >> students[i].kor >> students[i].eng >>
        students[i].math;

  sort(students, students + n, cmp);

  for (int i = 0; i < n; i++)
    cout << students[i].name << " " << students[i].kor << " " << students[i].eng
         << " " << students[i].math << endl;
  return 0;
}