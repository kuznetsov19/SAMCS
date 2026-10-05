#include <iomanip>
#include <iostream>

const long double cEps = 1e-10;
const int cInf = 1001;
const int cAccuracy = 20;

long double F(int a, int b, int c, int d, long double x) {
  return a * x * x * x + b * x * x + c * x + d;
}

long double SolveCubicEquation(int a, int b, int c, int d) {
  long double left = -cInf;
  long double right = cInf;
  while (right - left > cEps) {
    long double mid = (left + right) / 2;
    if (F(a, b, c, d, mid) > 0) {
      if (a > 0) {
        right = mid;
      } else {
        left = mid;
      }
    } else {
      if (a > 0) {
        left = mid;
      } else {
        right = mid;
      }
    }
  }
  return right;
}

int main() {
  int a;
  int b;
  int c;
  int d;
  std::cin >> a >> b >> c >> d;
  std::cout << std::fixed << std::setprecision(cAccuracy)
            << SolveCubicEquation(a, b, c, d);
}