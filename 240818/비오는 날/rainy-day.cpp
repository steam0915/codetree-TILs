#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class imformation {
public:
  string Date;
  string Day;
  string Weather;
};
int n;

int main() {
  imformation imf[100];
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> imf[i].Date >> imf[i].Day >> imf[i].Weather;

  imformation ans = {"9999-99-99", "", ""};

  for (int i = 0; i < n; i++) {
    if (imf[i].Weather == "Rain" && imf[i].Date < ans.Date)
      ans = imf[i];
  }

  cout << ans.Date << " " << ans.Day << " " << ans.Weather;
  return 0;
}