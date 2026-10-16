#include <iostream>
#include <stack>
#include <vector>

int main() {
  std::string s;
  std::getline(std::cin, s);
  std::vector<char> v;
  for (int i = 0; i < static_cast<int>(s.length()); i += 2) {
    v.push_back(s[i]);
  }
  std::stack<int> st;
  for (auto el : v) {
    if (el == '+') {
      int b = st.top();
      st.pop();
      int a = st.top();
      st.pop();
      st.push(a + b);
    } else if (el == '-') {
      int b = st.top();
      st.pop();
      int a = st.top();
      st.pop();
      st.push(a - b);
    } else if (el == '*') {
      int b = st.top();
      st.pop();
      int a = st.top();
      st.pop();
      st.push(a * b);
    } else {
      st.push(el - '0');
    }
  }
  std::cout << st.top();
}