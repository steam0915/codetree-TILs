#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m, ans = -1e9;
int arr[10][10];

bool safe(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }

bool Overlap(pair<int, int> A1, pair<int, int> A2, pair<int, int> B1,
             pair<int, int> B2) {

  return !(A1.first > B2.first || A2.first < B1.first ||
           A2.second < B1.second || A1.second > B2.second);
}

int Make_Sum(pair<int, int> A1, pair<int, int> A2) {
  int sum = 0;

  for (int x = A1.first; x <= A2.first; x++)
    for (int y = A1.second; y <= A2.second; y++)
      sum += arr[x][y];

  return sum;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];

  for (int x1 = 0; x1 < n; x1++)
    for (int y1 = 0; y1 < m; y1++)

      for (int x2 = 0; x2 < n; x2++)
        for (int y2 = 0; y2 < m; y2++) {

          for (int x1_len = 0; x1_len < n; x1_len++)
            for (int y1_len = 0; y1_len < m; y1_len++)

              for (int x2_len = 0; x2_len < n; x2_len++)
                for (int y2_len = 0; y2_len < m; y2_len++)

                  if (safe(x1 + x1_len, y1 + y1_len) &&
                      safe(x2 + x2_len, y2 + y2_len) &&
                      !Overlap({x1, y1}, {x1 + x1_len, y1 + y1_len}, {x2, y2},
                               {x2 + x2_len, y2 + y2_len})) {

                    ans =
                        max(ans,
                            Make_Sum({x1, y1}, {x1 + x1_len, y1 + y1_len}) +
                                Make_Sum({x2, y2}, {x2 + x2_len, y2 + y2_len}));

                    if (Make_Sum({x1, y1}, {x1 + x1_len, y1 + y1_len}) +
                            Make_Sum({x2, y2}, {x2 + x2_len, y2 + y2_len}) ==
                        100)
                      cout << x1 << " " << y1 << " " << x1 + x1_len << " "
                           << y1 + y1_len << " " << x2 << " " << y2 << " "
                           << x2 + x2_len << " " << y2 + y2_len << endl;
                  }
        }

  cout << ans;
  return 0;
}