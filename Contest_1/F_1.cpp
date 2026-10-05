#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    res = res ^ x;
  }
  std::cout << res;
}