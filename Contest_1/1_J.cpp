#include <iostream>
#include <vector>

int main() {
  int n;
  int d;
  std::cin >> n >> d;
  std::vector<int> a(n, -1);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  int i = 0;
  int j = 0;
  long long ans = 0;
  while (i < n && j < n) {
    if (a[j] - a[i] > d) {
      ans += n - j;
      i++;
    } else {
      j++;
    }
  }
  j -= 1;
  while (i < n && a[j] - a[i] > d) {
    ans++;
    i++;
  }
  std::cout << ans;
}