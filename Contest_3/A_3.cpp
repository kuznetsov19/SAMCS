#include <iostream>
#include <stack>

int main() {
  std::string s;
  std::cin >> s;
  std::stack<char> st;
  int i = 0;
  while (i < static_cast<int>(s.length())) {
    if (st.empty()) {
      if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
        std::cout << "NO";
        return 0;
      }
      st.push(s[i]);
    } else if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
      st.push(s[i]);
    } else {
      char c = st.top();
      if ((c == '[' && s[i] == ']') || (c == '{' && s[i] == '}') ||
          (c == '(' && s[i] == ')')) {
        st.pop();
      } else {
        std::cout << "NO";
        return 0;
      }
    }
    i++;
  }
  if (st.empty()) {
    std::cout << "YES";
    return 0;
  }
  std::cout << "NO";
}