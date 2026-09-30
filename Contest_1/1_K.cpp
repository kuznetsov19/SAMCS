#include <iostream>

long long Solve(long long a, long long k, long long b, long long m,
                long long x) {
  long long left = 0;
  long long right = (2 * x / (a + b)) + 1;
  while (right - left > 1) {
    long long mid = (left + right) / 2;
    if ((a * (mid - (mid / k))) + (b * (mid - (mid / m))) >= x) {
      right = mid;
    } else {
      left = mid;
    }
  }
  return right;
}

int main() {
  long long a;
  long long k;
  long long b;
  long long m;
  long long x;
  std::cin >> a >> k >> b >> m >> x;
  std::cout << Solve(a, k, b, m, x);
}
