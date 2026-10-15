#include <algorithm>
#include <iostream>
#include <vector>

struct Node {
  long long a;
  long long b;
  int ind;
};

bool Comp1(const Node& а, const Node& b) { return а.a < b.a; }

bool Comp2(const Node& a, const Node& b) { return a.b > b.b; }

int main() {
  int n;
  std::cin >> n;
  std::vector<Node> jobs(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> jobs[i].a;
    jobs[i].ind = i + 1;
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> jobs[i].b;
  }

  std::vector<Node> first;
  std::vector<Node> second;
  for (int i = 0; i < n; ++i) {
    if (jobs[i].a <= jobs[i].b) {
      first.push_back(jobs[i]);
    } else {
      second.push_back(jobs[i]);
    }
  }
  std::sort(first.begin(), first.end(), Comp1);
  std::sort(second.begin(), second.end(), Comp2);
  std::vector<Node> order = first;
  for (const auto& i : second) {
    order.push_back(i);
  }

  long long end_a = 0;
  long long end_b = 0;
  for (int i = 0; i < n; ++i) {
    end_a += order[i].a;
    end_b = std::max(end_a, end_b) + order[i].b;
  }

  std::cout << end_b << '\n';
  for (int i = 0; i < n; ++i) {
    std::cout << order[i].ind << ' ';
  }
  std::cout << '\n';
  for (int i = 0; i < n; ++i) {
    std::cout << order[i].ind << ' ';
  }
}
