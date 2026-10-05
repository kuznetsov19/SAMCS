#include <iostream>
#include <vector>

struct int1 {
  int l;
  int r;
};

std::vector<int1> Merge(const std::vector<int1>& a,
                        const std::vector<int1>& b) {
  int n = (int)a.size();
  int m = (int)b.size();
  std::vector<int1> c;
  int i = 0;
  int j = 0;
  while (i < n && j < m) {
    if (a[i].l <= b[j].l) {
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

std::vector<int1> MergeSort(std::vector<int1> segments) {
  if ((int)segments.size() == 1) {
    return segments;
  }
  int mid = (int)segments.size() / 2;
  std::vector<int1> left(segments.begin(), segments.begin() + mid);
  std::vector<int1> right(segments.begin() + mid, segments.end());
  return Merge(MergeSort(left), MergeSort(right));
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int1> segments(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> segments[i].l >> segments[i].r;
  }
  std::vector<int1> vec = MergeSort(segments);
  std::vector<int1> ans;
  int1 cur = vec[0];
  for (auto& el : vec) {
    if (el.l <= cur.r) {
      cur.r = std::max(cur.r, el.r);
    } else {
      ans.push_back(cur);
      cur.l = el.l;
      cur.r = el.r;
    }
  }
  ans.push_back(cur);
  std::cout << ans.size() << '\n';
  for (auto el : ans) {
    std::cout << el.l << ' ' << el.r << '\n';
  }
}