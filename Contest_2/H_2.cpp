#include <cstdint>
#include <iostream>
#include <vector>

std::vector<uint32_t> Merge(const std::vector<uint32_t>& a,
                            const std::vector<uint32_t>& b) {
  int n = static_cast<int>(a.size());
  int m = static_cast<int>(b.size());
  std::vector<uint32_t> c;
  int i = 0;
  int j = 0;
  while (i < n && j < m) {
    if (a[i] <= b[j]) {
      c.push_back(a[i]);
      i++;
    } else {
      c.push_back(b[j]);
      j++;
    }
  }
  while (i < n) {
    c.push_back(a[i]);
    i++;
  }
  while (j < m) {
    c.push_back(b[j]);
    j++;
  }
  return c;
}

std::vector<uint32_t> MergeSort(std::vector<uint32_t> segments) {
  if (static_cast<int>(segments.size()) == 1) {
    return segments;
  }
  int mid = static_cast<int>(segments.size()) / 2;
  std::vector<uint32_t> left(segments.begin(), segments.begin() + mid);
  std::vector<uint32_t> right(segments.begin() + mid, segments.end());
  return Merge(MergeSort(left), MergeSort(right));
}

int MedianOf5(const std::vector<uint32_t>& a, int i1, int i2, int i3, int i4,
              int i5) {
  if (a[i1] > a[i2]) {
    std::swap(i1, i2);
  }
  if (a[i3] > a[i4]) {
    std::swap(i3, i4);
  }
  if (a[i2] > a[i4]) {
    std::swap(i1, i3);
    std::swap(i2, i4);
  }
  if (a[i3] > a[i5]) {
    std::swap(i3, i5);
  }
  if (a[i2] > a[i5]) {
    std::swap(i1, i3);
    std::swap(i2, i5);
  }

  if (a[i2] > a[i3]) {
    return i2;
  }
  return i3;
}

uint32_t MedianOfMedians(std::vector<uint32_t>& a, int left, int right) {
  int n = right - left;

  if (n <= 5) {
    std::vector<uint32_t> part(a.begin() + left, a.begin() + right);
    part = MergeSort(part);
    for (int i = 0; i < n; i++) {
      a[left + i] = part[i];
    }
    return a[left + n / 2];
  }

  int j = left;

  for (int i = left; i + 4 < right; i += 5) {
    int id = MedianOf5(a, i, i + 1, i + 2, i + 3, i + 4);

    std::swap(a[j], a[id]);
    j++;
  }

  return MedianOfMedians(a, left, j);
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

const int cShift = 8;  // сдвиг на 8 бит из генератора в условии

uint32_t NextRand24(uint32_t& cur, uint32_t a, uint32_t b) {
  cur = cur * a + b;  // переполнение uint32_t задумано условием
  return cur >> cShift;
}

uint32_t NextRand32(uint32_t& cur, uint32_t a, uint32_t b) {
  uint32_t x = NextRand24(cur, a, b);
  uint32_t y = NextRand24(cur, a, b);
  return (x << cShift) ^ y;
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
  uint32_t y = QuickSelect(vec, 0, static_cast<int>(vec.size()) - 1, n / 2);
  uint64_t sm = 0;
  for (uint32_t el : vec) {
    sm += (el > y) ? el - y : y - el;
  }
  std::cout << sm;
}
