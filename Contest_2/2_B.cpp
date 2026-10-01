#include <iostream>
#include <random>
#include <vector>

int MedianOf5(std::vector<int>& A, int i1, int i2, int i3, int i4, int i5) {
  if (A[i1] > A[i2]) {
    std::swap(i1, i2);
  }
  if (A[i3] > A[i4]) {
    std::swap(i3, i4);
  }
  if (A[i2] > A[i4]) {
    std::swap(i1, i3);
    std::swap(i2, i4);
  }
  if (A[i3] > A[i5]) {
    std::swap(i3, i5);
  }
  if (A[i2] > A[i5]) {
    std::swap(i1, i3);
    std::swap(i2, i5);
  }

  if (A[i2] > A[i3]) {
    return i2;
  }
  return i3;
}

int main() {}