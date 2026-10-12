#include <algorithm>
#include <iostream>
#include <vector>

struct Job {
  long long a;
  long long b;
  int ind;
};

bool Comp1(const Job& а, const Job& b) { return а.a < b.a; }

bool Comp2(const Job& a, const Job& b) { return a.b > b.b; }

int main() {
  int n;
  std::cin >> n;
  std::vector<Job> jobs(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> jobs[i].a;
    jobs[i].ind = i + 1;
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> jobs[i].b;
  }

  std::vector<Job> first;
  std::vector<Job> second;
  for (int i = 0; i < n; ++i) {
    if (jobs[i].a <= jobs[i].b) {
      first.push_back(jobs[i]);
    } else {
      second.push_back(jobs[i]);
    }
  }
  std::sort(first.begin(), first.end(), Comp1);
  std::sort(second.begin(), second.end(), Comp2);
  std::vector<Job> order = first;
  order.insert(order.end(), second.begin(), second.end());

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
