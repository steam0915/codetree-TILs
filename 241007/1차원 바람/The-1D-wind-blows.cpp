#include <iostream>
#include <vector>

using namespace std;

class Wind {
public:
  int row;
  char direction;
};

int n, m, q;
int arr[105][105];
Wind wind[105];

bool safe(int x) { return 1 <= x && x <= n; }

bool Matching(int row1, int row2) {
  for (int i = 1; i <= m; i++)
    if (arr[row1][i] == arr[row2][i])
      return true;

  return false;
}

bool Make_Dir(char a) {
  if (a == 'L')
    return 1;
  else
    return 0;
}

void Move_Left(int row) {
  int temp = arr[row][1];

  for (int i = 1; i < m; i++)
    arr[row][i] = arr[row][i + 1];

  arr[row][m] = temp;
}

void Move_Right(int row) {
  int temp = arr[row][m];

  for (int i = m; i > 1; i--)
    arr[row][i] = arr[row][i - 1];

  arr[row][1] = temp;
}

void Call_Move(bool condition, int row) {
  if (condition)
    Move_Right(row);

  else
    Move_Left(row);
}

int main() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> arr[i][j];

  for (int i = 1; i <= q; i++)
    cin >> wind[i].row >> wind[i].direction;

  for (int w = 1; w <= q; w++) {
    Call_Move(Make_Dir(wind[w].direction), wind[w].row);

    int dx = 1;
    while (safe(wind[w].row + dx) &&
           Matching(wind[w].row + dx, wind[w].row + dx - 1)) {
      bool dir;
      if (dx % 2 == 0)
        dir = Make_Dir(wind[w].direction);

      else
        dir = !Make_Dir(wind[w].direction);

      Call_Move(dir, wind[w].row + dx);

      dx++;
    }

    dx = 1;
    while (safe(wind[w].row - dx) &&
           Matching(wind[w].row - dx, wind[w].row - dx + 1)) {
      bool dir;
      if (dx % 2 == 0)
        dir = Make_Dir(wind[w].direction);

      else
        dir = !Make_Dir(wind[w].direction);

      Call_Move(dir, wind[w].row - dx);

      dx++;
    }

  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      cout << arr[i][j] << " ";
    cout << endl;
  }

  return 0;
}