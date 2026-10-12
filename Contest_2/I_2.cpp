#include <algorithm>
#include <iostream>
#include <vector>

struct Job {
  long long a;
  long long b;
  int ind;
};

// Работы с a <= b: по возрастанию времени у первого учителя.
bool CompFirst(const Job& lhs, const Job& rhs) { return lhs.a < rhs.a; }

// Работы с a > b: по убыванию времени у второго учителя.
bool CompSecond(const Job& lhs, const Job& rhs) { return lhs.b > rhs.b; }

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

  // Правило Джонсона: сначала работы с a <= b, потом работы с a > b.
  std::vector<Job> first;
  std::vector<Job> second;
  for (int i = 0; i < n; ++i) {
    if (jobs[i].a <= jobs[i].b) {
      first.push_back(jobs[i]);
    } else {
      second.push_back(jobs[i]);
    }
  }
  std::sort(first.begin(), first.end(), CompFirst);
  std::sort(second.begin(), second.end(), CompSecond);
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
  std::cout << '\n';
}
