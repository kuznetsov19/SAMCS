#include <iostream>
#include <vector>

std::vector<int> cnt;

struct Node {
  int val, ind;
};

std::vector<Node> Merge(const std::vector<Node>& a,
                        const std::vector<Node>& b) {
  int n = static_cast<int>(a.size());
  int m = static_cast<int>(b.size());
  std::vector<Node> c;
  int i = 0;
  int j = 0;
  int cnt_r = 0;
  while (i < n && j < m) {
    if (a[i].val <= b[j].val) {
      c.push_back(a[i]);
      i++;
      cnt[a[i].ind] += cnt_r;
    } else {
      c.push_back(b[j]);
      j++;
      cnt_r++;
    }
  }
  while (i < n) {
    c.push_back(a[i]);
    i++;
    cnt[a[i].ind] += cnt_r;
  }
  while (j < m) {
    c.push_back(b[j]);
    j++;
  }
  return c;
}

std::vector<Node> MergeSort(std::vector<Node> segments) {
  if (static_cast<int>(segments.size()) == 1) {
    return segments;
  }
  int mid = static_cast<int>(segments.size()) / 2;
  std::vector<Node> left(segments.begin(), segments.begin() + mid);
  std::vector<Node> right(segments.begin() + mid, segments.end());
  return Merge(MergeSort(left), MergeSort(right));
}

int main() {
  int n;
  std::cin >> n;
  cnt.resize(n);
  std::vector<Node> v(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i].val;
    v[i].ind = i;
  }
  std::vector<Node> vec = MergeSort(v);
  for (auto el : cnt) {
    std::cout << el << ' ';
  }
}