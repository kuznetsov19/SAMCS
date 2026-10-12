#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> a(n);
  std::vector<long long> b(n);
  for (auto& x : a) {
    std::cin >> x;
  }
  for (auto& x : b) {
    std::cin >> x;
  }

  // Правило Джонсона: сначала работы с a <= b по возрастанию a,
  // потом работы с a > b по убыванию b.
  std::vector<int> first;
  std::vector<int> second;
  for (int i = 0; i < n; ++i) {
    if (a[i] <= b[i]) {
      first.push_back(i);
    } else {
      second.push_back(i);
    }
  }
  std::sort(first.begin(), first.end(),
            [&](int i, int j) { return a[i] < a[j]; });
  std::sort(second.begin(), second.end(),
            [&](int i, int j) { return b[i] > b[j]; });
  std::vector<int> order = first;
  order.insert(order.end(), second.begin(), second.end());

  long long end_a = 0;
  long long end_b = 0;
  for (int i : order) {
    end_a += a[i];
    end_b = std::max(end_a, end_b) + b[i];
  }

  std::cout << end_b << '\n';
  for (int i : order) {
    std::cout << i + 1 << ' ';
  }
  std::cout << '\n';
  for (int i : order) {
    std::cout << i + 1 << ' ';
  }
  std::cout << '\n';
}
