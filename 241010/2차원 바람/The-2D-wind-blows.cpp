#include <deque>
#include <iostream>

using namespace std;

class Pos {
public:
  int row;
  int col;
};

int n, m, q;
int arr[105][105];

bool safe(int x, int y) { return 1 <= x && x <= n && 1 <= y && y <= m; }

void Make_New_Arr(Pos p1, Pos p2, deque<int> dq) {

  for (int col = p1.col + 1; col <= p2.col; col++) {
    arr[p1.row][col] = dq.front();
    dq.pop_front();
  }

  for (int row = p1.row + 1; row <= p2.row; row++) {
    arr[row][p2.col] = dq.front();
    dq.pop_front();
  }

  for (int col = p2.col - 1; col >= p1.col; col--) {
    arr[p2.row][col] = dq.front();
    dq.pop_front();
  }
  for (int row = p2.row - 1; row >= p1.row; row--) {
    arr[row][p1.col] = dq.front();
    dq.pop_front();
  }
}

void Simulate(Pos p1, Pos p2) {
  deque<int> dq;

  for (int col = p1.col + 1; col <= p2.col; col++)
    dq.push_back(arr[p1.row][col]);

  for (int row = p1.row + 1; row <= p2.row; row++)
    dq.push_back(arr[row][p2.col]);

  for (int col = p2.col - 1; col >= p1.col; col--)
    dq.push_back(arr[p2.row][col]);

  for (int row = p2.row - 1; row >= p1.row; row--)
    dq.push_back(arr[row][p1.col]);

  int temp = dq.back();
  dq.pop_back();
  dq.push_front(temp);

  Make_New_Arr(p1, p2, dq);
}

void New_arr(Pos p1, Pos p2) {
  int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
  deque<int> dq;
  for (int row = p1.row; row <= p2.row; row++)
    for (int col = p1.col; col <= p2.col; col++) {
      int sum = arr[row][col], cnt = 1;
      for (int i = 0; i < 4; i++) {
        int nx = dx[i] + row, ny = dy[i] + col;
        if (safe(nx, ny)) {
          sum += arr[nx][ny];
          cnt++;
        }
      }
      dq.push_back(sum / cnt);
    }

  for (int row = p1.row; row <= p2.row; row++)
    for (int col = p1.col; col <= p2.col; col++) {
      arr[row][col] = dq.front();
      dq.pop_front();
    }
}

int main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> arr[i][j];

  while (q--) {
    Pos p1, p2;
    cin >> p1.row >> p1.col >> p2.row >> p2.col;

    Simulate(p1, p2);

    New_arr(p1, p2);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      cout << arr[i][j] << " ";
    cout << endl;
  }
  return 0;
}