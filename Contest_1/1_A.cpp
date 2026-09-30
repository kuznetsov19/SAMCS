#include <iostream>
#include <vector>

std::vector<int> PrefMinLeft(std::vector<int>& v) {
  std::vector<int> pref_mn(v.size(), -1);
  pref_mn[0] = v[0];
  for (int i = 1; i < (int)v.size(); ++i) {
    pref_mn[i] = std::min(pref_mn[i - 1], v[i]);
  }
  return pref_mn;
}

std::vector<int> PrefMinRight(std::vector<int>& v) {
  std::vector<int> pref_mn(v.size(), -1);
  pref_mn[v.size() - 1] = v[v.size() - 1];
  for (int i = (int)v.size() - 2; i >= 0; --i) {
    pref_mn[i] = std::min(pref_mn[i + 1], v[i]);
  }
  return pref_mn;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
  }
  int q;
  std::cin >> q;
  std::vector<int> pref_mn_left = PrefMinLeft(v);
  std::vector<int> pref_mn_right = PrefMinRight(v);
  while (q-- > 0) {
    int l;
    int r;
    std::cin >> l >> r;
    std::cout << std::min(pref_mn_left[l - 1], pref_mn_right[r - 1]) << '\n';
  }
}
