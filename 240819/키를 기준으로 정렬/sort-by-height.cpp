#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Student {
public:
  string name;
  int height;
  int weight;
};

int n;
Student students[10];

bool cmp(const Student &a, const Student &b) { return a.height < b.height; }

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> students[i].name >> students[i].height >> students[i].weight;

  sort(students, students + n, cmp);

  for (int i = 0; i < n; i++)
    cout << students[i].name << " " << students[i].height << " "
         << students[i].weight << endl;
  return 0;
}