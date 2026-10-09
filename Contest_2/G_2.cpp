#include <algorithm>
#include <iostream>
#include <vector>

struct Node {
  int val;
  int ind;
};

bool Comp(Node a, Node b) {
  if (a.val == b.val) {
    return a.ind < b.ind;
  }
  return a.val < b.val;
}

bool Check(std::vector<int>& b, std::vector<int>& c, int i, int j_ans,
           int k_ans) {}

int main() {
  int s;
  std::cin >> s;
  int n;
  std::cin >> n;
  std::vector<Node> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i].val;
    a[i].ind = i;
  }
  std::cin >> n;
  std::vector<Node> b(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> b[i].val;
    b[i].ind = i;
  }
  std::cin >> n;
  std::vector<Node> c(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> c[i].val;
    c[i].ind = i;
  }
  std::sort(b.begin(), b.end(), Comp);
  std::sort(c.begin(), c.end(), Comp);

  int j_ans = -1;
  int k_ans = -1;
  for (int i = 0; i < static_cast<int>(a.size()); ++i) {
    if (Check(b, c, i, j_ans, k_ans)) {
      std::cout << i << ' ' << j_ans << ' ' << k_ans;
      return 0;
    }
  }
  std::cout << -1;
}