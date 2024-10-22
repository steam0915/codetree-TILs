#include <iostream>

using namespace std;

int Grid[4][4];

void PushToDir(char dir) {
  if (dir == 'L') {
    for (int x = 0; x < 4; x++) {
      int i = 0;
      int temp_arr[4] = {};

      for (int y = 0; y < 4; y++)
        if (Grid[x][y] != 0)
          temp_arr[i++] = Grid[x][y];

      for (int y = 0; y < 4; y++)
        Grid[x][y] = temp_arr[y];
    }
  }

  else if (dir == 'R') {
    for (int x = 0; x < 4; x++) {
      int i = 3;
      int temp_arr[4] = {};

      for (int y = 3; y >= 0; y--)
        if (Grid[x][y] != 0)
          temp_arr[i--] = Grid[x][y];

      for (int y = 0; y < 4; y++)
        Grid[x][y] = temp_arr[y];
    }
  }

  else if (dir == 'U') {
    for (int y = 0; y < 4; y++) {
      int i = 0;
      int temp_arr[4] = {};

      for (int x = 0; x < 4; x++)
        if (Grid[x][y] != 0)
          temp_arr[i++] = Grid[x][y];

      for (int x = 0; x < 4; x++)
        Grid[x][y] = temp_arr[x];
    }
  }

  else {
    for (int y = 0; y < 4; y++) {
      int i = 3;
      int temp_arr[4] = {};

      for (int x = 3; x >= 0; x--)
        if (Grid[x][y] != 0)
          temp_arr[i--] = Grid[x][y];

      for (int x = 0; x < 4; x++)
        Grid[x][y] = temp_arr[x];
    }
  }
}

void Make_Sum(char dir) {
  if (dir == 'L') {
    for (int x = 0; x < 4; x++)
      for (int y = 0; y < 3; y++)
        if (Grid[x][y] == Grid[x][y + 1]) {
          Grid[x][y] *= 2;
          Grid[x][y + 1] = 0;
        }
  }

  else if (dir == 'R') {
    for (int x = 0; x < 4; x++)
      for (int y = 3; y > 0; y--)
        if (Grid[x][y] == Grid[x][y - 1]) {
          Grid[x][y] *= 2;
          Grid[x][y - 1] = 0;
        }
  }

  else if (dir == 'U') {
    for (int y = 0; y < 4; y++)
      for (int x = 0; x < 3; x++)
        if (Grid[x][y] == Grid[x + 1][y]) {
          Grid[x][y] *= 2;
          Grid[x + 1][y] = 0;
        }
  }

  else {
    for (int y = 0; y < 4; y++)
      for (int x = 3; x > 0; x--)
        if (Grid[x][y] == Grid[x - 1][y]) {
          Grid[x][y] *= 2;
          Grid[x - 1][y] = 0;
        }
  }
}

int main() {
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      cin >> Grid[i][j];

  char dir;
  cin >> dir;

  PushToDir(dir);
  Make_Sum(dir);
  PushToDir(dir);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++)
      cout << Grid[i][j] << " ";
    cout << endl;
  }
  return 0;
}