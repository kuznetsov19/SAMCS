#include <iostream>
#include <stack>
#include <vector>

bool Check(std::string& s) { return s == "*" || s == "+" || s == "-"; }

int main() {
  std::string s;
  std::getline(std::cin, s);
  std::vector<std::string> v;
  std::string cur = "";
  for (int i = 0; i < static_cast<int>(s.length()); ++i) {
    if (s[i] == ' ') {
      if (!cur.empty()) {
        v.push_back(cur);
        cur.clear();
      }
    } else {
      cur += s[i];
    }
  }
  if (!cur.empty()) v.push_back(cur);
  std::stack<int> st;
  for (int i = 0; i < static_cast<int>(v.size()); ++i) {
    if (!Check(v[i])) {
      st.push(std::stoi(v[i]));
    } else {
      int tmp = st.top();
      st.pop();
      if (s[i] == '*') {
        tmp *= st.top();
      } else if (s[i] == '-') {
        tmp -= st.top();
      } else {
        tmp += st.top();
      }
      st.pop();
      st.push(tmp);
    }
  }
  std::cout << st.top();
}