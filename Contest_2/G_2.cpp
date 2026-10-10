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

bool Check(const std::vector<Node>& b, const std::vector<Node>& c, int value,
           int& j_ans, int& k_ans) {
  int j = 0;
  int k = static_cast<int>(c.size()) - 1;
  std::pair<int, int> bst = {-1, -1};
  while (j < static_cast<int>(b.size()) && k >= 0) {
    if (b[j].val + c[k].val > value) {
      k--;
    } else if (b[j].val + c[k].val < value) {
      j++;
    } else {
      if (bst.first == -1 || b[j].ind < bst.first ||
          (b[j].ind == bst.first && c[k].ind < bst.second)) {
        bst = {b[j].ind, c[k].ind};
      }
      --k;
    }
  }
  if (bst.first != -1) {
    j_ans = bst.first;
    k_ans = bst.second;
  }
  return bst.first != -1;
}

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
    if (Check(b, c, s - a[i].val, j_ans, k_ans)) {
      std::cout << i << ' ' << j_ans << ' ' << k_ans;
      return 0;
    }
  }
  std::cout << -1;
}