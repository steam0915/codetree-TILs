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
  return a.kor + a.eng + a.math < b.kor + b.eng + b.math;
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