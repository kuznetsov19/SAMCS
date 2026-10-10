#include <iostream>
#include <vector>

std::vector<int> Merge(const std::vector<int>& a, const std::vector<int>& b) {
  int n = (int)a.size();
  int m = (int)b.size();
  std::vector<int> c;
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

std::vector<int> MergeSort(std::vector<int> segments) {
  if ((int)segments.size() == 1) {
    return segments;
  }
  int mid = (int)segments.size() / 2;
  std::vector<int> left(segments.begin(), segments.begin() + mid);
  std::vector<int> right(segments.begin() + mid, segments.end());
  return Merge(MergeSort(left), MergeSort(right));
}

int MedianOf5(const std::vector<int>& a, int i1, int i2, int i3, int i4,
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

int MedianOfMedians(std::vector<int>& a, int left, int right) {
  int n = right - left;

  if (n <= 5) {
    std::vector<int> part(a.begin() + left, a.begin() + right);
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

int QuickSelect(std::vector<int>& a, int left, int right, int k) {
  int pivot = MedianOfMedians(a, left, right);
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

int main() {
  int n;
  int a;
  int b;
  std::cin >> n >> a >> b;
  std::vector<int> vec(n);
  int y = QuickSelect(vec, 0, static_cast<int>(vec.size()) - 1, n / 2);
  int sm = 0;
  for (auto el : vec) {
    sm += abs(el - y);
  }
}