#include <iostream>

using namespace std;

int n;
int r, c;
int len1, len2, len3, len4;
bool spin;

#define Left 0
#define Right 1
int arr[105][105];

void circulate(bool spin) {
  int temp = arr[r][c];
  int x = r, y = c;
  if (spin == Left) {
    int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1};

    while (len4--) {
      int nx = x + dx[0], ny = y + dy[0];
      arr[x][y] = arr[nx][ny];
      x = nx, y = ny;
    }

    while (len3--) {
      int nx = x + dx[1], ny = y + dy[1];
      arr[x][y] = arr[nx][ny];
      x = nx, y = ny;
    }

    while (len2--) {
      int nx = x + dx[2], ny = y + dy[2];
      arr[x][y] = arr[nx][ny];
      x = nx, y = ny;
    }

    len1--;
    while (len1--) {
      int nx = x + dx[3], ny = y + dy[3];
      arr[x][y] = arr[nx][ny];
      x = nx, y = ny;
    }

    arr[x][y] = temp;
  }

  else {
    int dx[4] = {-1, -1, 1, 1}, dy[4] = {1, -1, -1, 1};

    while (len1--) {
      int nx = x + dx[0], ny = y + dy[0];
      arr[x][y] = arr[nx][ny];
      x = nx, y = ny;
    }

    while (len2--) {
      int nx = x + dx[1], ny = y + dy[1];
      arr[x][y] = arr[nx][ny];
      x = nx, y = ny;
    }

    while (len3--) {
      int nx = x + dx[2], ny = y + dy[2];
      arr[x][y] = arr[nx][ny];
      x = nx, y = ny;
    }

    len4--;
    while (len4--) {
      int nx = x + dx[3], ny = y + dy[3];
      arr[x][y] = arr[nx][ny];
      x = nx, y = ny;
    }

    arr[x][y] = temp;
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> arr[i][j];

  cin >> r >> c;
  cin >> len1 >> len2 >> len3 >> len4;
  cin >> spin;

  (spin) ? circulate(Right) : circulate(Left);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      cout << arr[i][j] << " ";
    cout << endl;
  }
  return 0;
}