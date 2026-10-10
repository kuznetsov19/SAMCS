#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

uint32_t QuickSelect(std::vector<uint32_t>& a, int left, int right, int k);

uint32_t MedianOfMedians(std::vector<uint32_t>& a, int left, int right) {
  int n = right - left;

  if (n <= 5) {
    std::sort(a.begin() + left, a.begin() + right);
    return a[left + (n / 2)];
  }

  int j = left;
  for (int i = left; i < right; i += 5) {
    int end = std::min(i + 5, right);
    std::sort(a.begin() + i, a.begin() + end);
    std::swap(a[j], a[i + ((end - i) / 2)]);
    ++j;
  }

  return QuickSelect(a, left, j, left + ((j - left) / 2));
}

uint32_t QuickSelect(std::vector<uint32_t>& a, int left, int right, int k) {
  uint32_t pivot = MedianOfMedians(a, left, right);
  int l = left;
  int i = left;
  int r = right - 1;

  while (i <= r) {
    if (a[i] < pivot) {
      std::swap(a[l], a[i]);
      l++;
      i++;
    } else if (a[i] == pivot) {
      i++;
    } else {
      std::swap(a[i], a[r]);
      r--;
    }
  }

  if (k < l) {
    return QuickSelect(a, left, l, k);
  }
  if (l <= k && k <= r) {
    return pivot;
  }
  return QuickSelect(a, r + 1, right, k);

}

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
