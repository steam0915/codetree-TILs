#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Spy {
public:
  char name;
  int score;
};

int main() {
  int min_score = 1e9;
  int min_spy;
  Spy spys[5];
  for (int i = 0; i < 5; i++)
    cin >> spys[i].name >> spys[i].score;

  for (int i = 0; i < 5; i++) {
    if (min_score > spys[i].score) {
      min_score = spys[i].score;
      min_spy = i;
    }
  }

  cout << spys[min_spy].name << " " << spys[min_spy].score;
  return 0;
}