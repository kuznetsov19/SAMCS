#include <iostream>
#include <vector>

int N;
std::vector<int> cnt(N);

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
      cnt[i + j] = n - i;
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

int main() {
  std::cin >> N;
  std::vector<int> segments(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> segments[i];
  }
  std::vector<int> vec = MergeSort(segments);
  for (auto el : cnt) {
    std::cout << el << ' ';
  }
}