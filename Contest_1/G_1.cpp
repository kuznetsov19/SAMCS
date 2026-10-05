#include <iostream>
#include <vector>

std::vector<long long> MakeResArray(std::vector<long long>& diff_c,
                                    std::vector<long long>& diff_d) {
  int n = (int)diff_c.size() - 2;
  std::vector<long long> pref_sum(n + 1, 0);
  long long c = 0;
  long long d = 0;
  for (int i = 1; i <= n; ++i) {
    c += diff_c[i];
    d += diff_d[i];
    pref_sum[i] = pref_sum[i - 1] + c + (d * i);
  }
  return pref_sum;
}

int main() {
  int n;
  int m;
  std::cin >> n >> m;
  std::vector<long long> diff_c(n + 2, 0);
  std::vector<long long> diff_d(n + 2, 0);
  while (m-- > 0) {
    int l;
    int r;
    long long b;
    long long d;
    std::cin >> l >> r >> b >> d;
    diff_c[l] += b - (l * d);
    diff_c[r + 1] -= b - (l * d);
    diff_d[l] += d;
    diff_d[r + 1] -= d;
  }

  std::vector<long long> pref_sum = MakeResArray(diff_c, diff_d);

  int k;
  std::cin >> k;
  while (k-- > 0) {
    int l;
    int r;
    std::cin >> l >> r;
    std::cout << pref_sum[r] - pref_sum[l - 1] << '\n';
  }
}
