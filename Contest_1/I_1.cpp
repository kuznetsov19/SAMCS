#include <iostream>
#include <vector>

const int cInf = 1000000000;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;
  int m;
  std::cin >> n >> m;
  std::vector<int> a(n, 0);
  std::vector<int> b(m, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  for (int j = 0; j < m; ++j) {
    std::cin >> b[j];
  }
  int i = 0;
  int j = 0;
  int lst;
  int mn = cInf;
  std::string lst_color;
  if (a[i] >= b[j]) {
    lst = b[j];
    lst_color = "B";
    j++;
  } else {
    lst = a[i];
    lst_color = "A";
    i++;
  }
  while (i < n && j < m) {
    if (a[i] >= b[j]) {
      if (mn > b[j] - lst && lst_color == "A") {
        mn = b[j] - lst;
      }
      lst_color = "B";
      lst = b[j];
      j++;
    } else {
      if (mn > a[i] - lst && lst_color == "B") {
        mn = a[i] - lst;
      }
      lst_color = "A";
      lst = a[i];
      i++;
    }
  }
  while (i < n) {
    if (std::abs(a[i] - b[m - 1]) < mn) {
      mn = std::abs(a[i] - b[m - 1]);
    }
    i++;
  }
  while (j < m) {
    if (std::abs(a[n - 1] - b[j]) < mn) {
      mn = std::abs(a[n - 1] - b[j]);
    }
    j++;
  }
  std::cout << mn;
}