#include <iostream>

using namespace std;

int n, cnt;
int arr[100];

void Make_Move(int idx) {
  int temp = arr[0];

  for (int i = 1; i <= idx; i++)
    arr[i - 1] = arr[i];

  arr[idx] = temp;
}

bool Sorted() {
  for (int i = 0; i < n; i++)
    if (arr[i] != i + 1)
      return false;

  return true;
}

bool Sorted(int idx) {
  for (int i = idx + 1; i < n - 1; i++)
    if (arr[i] > arr[i + 1])
      return false;

  return true;
}

bool Bigger(int idx) {
  for (int i = idx + 1; i < n; i++)
    if (arr[0] >= arr[i])
      return false;

  return true;
}

bool Can_Move(int idx) { return Bigger(idx) && Sorted(idx); }

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  while (!Sorted()) {
    cnt++;

    for (int i = 1; i < n; i++) {
      if (Can_Move(i)) {
        Make_Move(i);
        break;
      }
    }
  }

  cout << cnt;
  return 0;
}