#include <cstdint>
#include <iostream>
#include <vector>

uint32_t QuickSelect(std::vector<int> vec, int l, int r, int k);

uint32_t MedianOfMedinas(std::vector<int> vec, int l, int r) {}

uint32_t NextRand24(uint32_t& cur, uint32_t a, uint32_t b) {
  cur = (cur * a) + b;
  return cur >> (4 + 4);
}

uint32_t NextRand32(uint32_t& cur, uint32_t a, uint32_t b) {
  uint32_t x = NextRand24(cur, a, b);
  uint32_t y = NextRand24(cur, a, b);
  return (x << (4 + 4)) ^ y;
}

int main() {
  int n;
  uint32_t a;
  uint32_t b;
  std::cin >> n >> a >> b;
  std::vector<uint32_t> vec(n);
  uint32_t cur = 0;
  for (int i = 0; i < n; ++i) {
    vec[i] = NextRand32(cur, a, b);
  }
  uint32_t y = QuickSelect(vec, 0, static_cast<int>(vec.size()), n / 2);
  uint64_t sm = 0;
  for (uint32_t el : vec) {
    if (el >= y) {
      sm += (el - y);
    } else {
      sm += (y - el);
    }
  }
  std::cout << sm;
}
