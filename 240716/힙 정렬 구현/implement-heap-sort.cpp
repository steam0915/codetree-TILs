#include <algorithm>
#include <iostream>

using namespace std;

int arr[100005];

void heapify(int max_range, int i) {
  int largest = i;
  int l = i * 2;
  int r = i * 2 + 1;

  if (l <= max_range && arr[largest] < arr[l])
    swap(largest, l);

  if (r <= max_range && arr[largest] < arr[r])
    swap(largest, r);

  if (largest != i) {
    swap(arr[largest], arr[i]);
    heapify(max_range, largest);
  }
}

void heap_sort(int max_range) {
  for (int i = max_range / 2; i >= 1; i--)
    heapify(max_range, i);

  for (int i = max_range; i > 1; i--) {
    swap(arr[1], arr[i]);
    heapify(i - 1, 1);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];

  heap_sort(n);

  for (int i = 1; i <= n; i++)
    cout << arr[i] << " ";
  return 0;
}