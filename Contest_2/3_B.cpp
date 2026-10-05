#include <algorithm>
#include <iostream>
#include <vector>

// const long long cHi = 1000000000000000000;

bool Check(std::vector<int>& v, long long mid, int k) {
  int last_covered = -1;
  int cnt = 0;
  for (int i = 0; i < static_cast<int>(v.size()); ++i) {
    if (last_covered == -1 || v[i] - v[last_covered] > mid) {
      last_covered = i;
      cnt += 1;
    }
  }
  return cnt <= k;
}

int main() {
  int n;
  int k;
  std::cin >> n >> k;
  std::vector<int> v(n, -1);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
  }
  sort(v.begin(), v.end());
  long long left = -1;
  long long right = (static_cast<long long>(2) * 2 * 2 * 5 * 5 * 5) *
                    (2 * 2 * 2 * 5 * 5 * 5) * (2 * 2 * 2 * 5 * 5 * 5) *
                    (2 * 2 * 2 * 5 * 5 * 5) * (2 * 2 * 2 * 5 * 5 * 5) *
                    (2 * 2 * 2 * 5 * 5 * 5);
  while (right - left > 1) {
    long long mid = left + ((right - left) / 2);
    if (Check(v, mid, k)) {
      left = mid;
    } else {
      right = mid - 1;
    }
  }
  std::cout << right;
}