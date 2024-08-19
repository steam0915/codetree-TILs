#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Student {
public:
  int height;
  int weight;
  int num;

  Student(int height, int weight, int num) {
    this->height = height;
    this->weight = weight;
    this->num = num;
  }
  Student() {}
};

int n;
Student students[1000];

bool cmp(const Student &a, const Student &b) {

  if (a.height == b.height) {

    if (a.weight == b.weight)
      return a.num < b.num;

    return a.weight > b.weight;
  }

  return a.height > b.height;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int height, weight;
    cin >> height >> weight;

    students[i] = Student(height, weight, i + 1);
  }

  sort(students, students + n, cmp);

  for (int i = 0; i < n; i++)
    cout << students[i].height << " " << students[i].weight << " "
         << students[i].num << endl;
  return 0;
}