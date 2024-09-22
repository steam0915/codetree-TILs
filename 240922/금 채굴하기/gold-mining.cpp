#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, ans, Range_Size = 0;
int arr[25][25];
bool Do_More = true;

bool safe(int x, int y) { return 0 <= x && x < n && 0 <= y && y < n; }

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];

  while (true) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int cnt = 0;
        queue<pair<int, int>> q;
        int visit[25][25] = {};
        int step[25][25] = {};

        visit[i][j] = true;
        q.push({i, j});

        while (!q.empty()) {
          int x = q.front().first, y = q.front().second;
          int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

          for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (safe(nx, ny) && !visit[nx][ny] && step[x][y] < Range_Size) {
              visit[nx][ny] = true;
              step[nx][ny] = step[x][y] + 1;
              q.push({nx, ny});
            }
          }

          q.pop();
        }

        bool end_time = true;
        for (int x = 0; x < n; x++)
          for (int y = 0; y < n; y++) {
            if (visit[x][y] && arr[x][y])
              cnt++;

            if (!visit[x][y])
              end_time = false;
          }

        int Gold_Value = cnt * m;
        if (Gold_Value >
            Range_Size * Range_Size + (Range_Size + 1) * (Range_Size + 1))
          ans = max(ans, cnt);

        if (end_time) {
          cout << ans;
          return 0;
        }
      }
    }
    Range_Size++;
  }
  return 0;
}