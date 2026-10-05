#include <cmath>
#include <iostream>

long long CalcSqrt(long long k) {
  long long m = (long long)sqrtl((long double)k);
  while (m > 0 && m * m > k) {
    --m;
  }
  while ((m + 1) * (m + 1) <= k) {
    ++m;
  }
  if (k - (m * m) > m) {
    ++m;
  }
  return m;
}

int main() {
  int t;
  std::cin >> t;
  while (t-- > 0) {
    long long k;
    std::cin >> k;
    std::cout << k + CalcSqrt(k) << '\n';
  }
}