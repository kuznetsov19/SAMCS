#include <iostream>
#include <vector>

bool BinarySearch(std::vector<int>& a, int b) {
  int left = -1;
  int right = (int)a.size();
  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (a[mid] < b) {
      left = mid;
    } else {
      right = mid;
    }
  }
  return right < (int)a.size() && a[right] == b;
}

int main() {
  int n;
  int k;
  std::cin >> n >> k;
  std::vector<int> a(n, -1);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  while (k-- > 0) {
    int b;
    std::cin >> b;
    if (BinarySearch(a, b)) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}