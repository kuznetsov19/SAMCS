#include <iostream>
#include <vector>

int Solve(int x, std::vector<int>& a, std::vector<int>& b) {
  int left = -1;
  int right = (int)a.size() - 1;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (a[mid] + x >= b[mid]) {
      right = mid;
    } else {
      left = mid;
    }
  }
  if (std::max(a[right] + x, b[right]) >
      std::max(a[right - 1] + x, b[right - 1])) {
    return right;
  }
  return right + 1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;
  std::cin >> n;
  std::vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::vector<int> b(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> b[i];
  }
  int q;
  std::cin >> q;
  while (q-- > 0) {
    int x;
    std::cin >> x;
    if (a[0] + x >= b[0]) {
      std::cout << 1 << '\n';
    } else if (a[n - 1] + x <= b[n - 1]) {
      std::cout << n << '\n';
    } else {
      std::cout << Solve(x, a, b) << '\n';
    }
  }
}