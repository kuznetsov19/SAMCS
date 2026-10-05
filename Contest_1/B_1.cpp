#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

const int cAccuracy = 20;

std::vector<long double> PrefLn(std::vector<double>& a) {
  std::vector<long double> pref_ln((int)a.size() + 1);
  pref_ln[0] = 0;
  for (int i = 1; i <= (int)a.size(); ++i) {
    pref_ln[i] = pref_ln[i - 1] + std::log(a[i - 1]);
  }
  return pref_ln;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<double> a(n, -1.0);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  int q;
  std::cin >> q;
  std::vector<long double> pref_ln = PrefLn(a);
  while (q-- > 0) {
    int l;
    int r;
    std::cin >> l >> r;
    std::cout << std::fixed << std::setprecision(cAccuracy)
              << exp((pref_ln[r + 1] - pref_ln[l]) / (r - l + 1)) << '\n';
  }
}