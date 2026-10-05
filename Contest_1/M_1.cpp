#include <iostream>
#include <vector>

int main() {
  int n;
  long long k;
  std::cin >> n >> k;

  std::vector<long long> a(n);
  long long sum = 0;
  long long max_el = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    sum += a[i];
    max_el = std::max(max_el, a[i]);
  }

  if (k > sum) {
    std::cout << -1;
    return 0;
  }

  long long left = 0;
  long long right = max_el;
  while (right - left > 1) {
    long long mid = (left + right) / 2;
    long long cnt = 0;
    for (int i = 0; i < n; ++i) {
      cnt += std::min(a[i], mid);
    }
    if (cnt <= k) {
      left = mid;
    } else {
      right = mid;
    }
  }
  right = left;

  long long cnt = 0;
  for (int i = 0; i < n; ++i) {
    cnt += std::min(a[i], right);
  }
  long long r = k - cnt;

  std::vector<long long> v(n);
  for (int i = 0; i < n; ++i) {
    v[i] = std::max(a[i] - right, 0LL);
  }

  int start = 0;
  for (int i = 0; i < n && r > 0; ++i) {
    if (v[i] > 0) {
      --v[i];
      --r;
      start = i + 1;
    }
  }
  if (start == n) {
    start = 0;
  }

  for (int step = 0; step < n; ++step) {
    int i = (start + step) % n;
    if (v[i] > 0) {
      std::cout << i + 1 << ' ';
    }
  }
}
