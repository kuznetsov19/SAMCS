#include <cstdint>
#include <iostream>
#include <stack>
#include <vector>

bool Check(std::string& s) { return s == "*" || s == "+" || s == "-"; }

int main() {
  std::string s;
  std::getline(std::cin, s);
  std::vector<char> v;
  for (int i = 0; i < static_cast<int>(s.length()); i += 2) {
    v.push_back(v[i]);
  }
  std::stack<int> st;
  for (int i = 0; i < static_cast<int>(v.size()); ++i) {
    if (!Check(v[i])) {
      st.push(std::stoi(v[i]));
    } else {
      int b = st.top();
      st.pop();
      int a = st.top();
      st.pop();
      if (s[i] == '*') {
        st.push(a * b);
      } else if (s[i] == '-') {
        st.push(a - b);
      } else {
        st.push(a + b);
      }
    }
  }
  std::cout << st.top();
}