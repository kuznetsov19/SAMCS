#include <iostream>
#include <string>
#include <vector>

bool Check(int k, std::string& s, std::string& t, std::vector<int>& p) {
  int n = (int)s.size();
  int m = (int)t.size();
  std::vector<bool> removed(n, false);
  for (int i = 0; i < k; ++i) {
    removed[p[i]] = true;
  }
  int j = 0;
  for (int i = 0; i < n; ++i) {
    if (!removed[i] && j < m && s[i] == t[j]) {
      ++j;
    }
  }
  return j == m;
}

int main() {
  std::string s;
  std::string t;
  std::cin >> s >> t;
  int n = (int)s.size();
  std::vector<int> p(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i];
    --p[i];
  }

  int left = 0;
  int right = n;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (Check(mid, s, t, p)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  std::cout << left;
}
