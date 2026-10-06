#include <iostream>
#include <vector>

struct Node {
  int val;
  int ind;
};

std::vector<Node> Merge(const std::vector<Node>& a, const std::vector<Node>& b,
                        std::vector<int>& cnt) {
  int n = static_cast<int>(a.size());
  int m = static_cast<int>(b.size());
  std::vector<Node> c;
  int i = 0;
  int j = 0;
  int cnt_r = 0;
  while (i < n && j < m) {
    if (a[i].val <= b[j].val) {
      cnt[a[i].ind] += cnt_r;
      c.push_back(a[i]);
      i++;
    } else {
      c.push_back(b[j]);
      j++;
      cnt_r++;
    }
  }
  while (i < n) {
    cnt[a[i].ind] += cnt_r;
    c.push_back(a[i]);
    i++;
  }
  while (j < m) {
    c.push_back(b[j]);
    j++;
  }
  return c;
}

std::vector<Node> MergeSort(std::vector<Node> segments, std::vector<int>& cnt) {
  if (static_cast<int>(segments.size()) == 1) {
    return segments;
  }
  int mid = static_cast<int>(segments.size()) / 2;
  std::vector<Node> left(segments.begin(), segments.begin() + mid);
  std::vector<Node> right(segments.begin() + mid, segments.end());
  return Merge(MergeSort(left, cnt), MergeSort(right, cnt), cnt);
}

int main() {
  int n;
  std::cin >> n;
  std::vector<Node> v(n);
  std::vector<int> cnt(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i].val;
    v[i].ind = i;
  }
  std::vector<Node> vec = MergeSort(v, cnt);
  for (auto el : cnt) {
    std::cout << el << ' ';
  }
}