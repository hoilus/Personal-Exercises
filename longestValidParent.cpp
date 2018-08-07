#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    int maxlen = 0;
    stack<int> stk;
    stk.push(-1);

    for (int i = 0; i < s.size(); i++) {
      int t = stk.top();
      if (t != -1 && s[i] == ')' && s[t] == '(') {
	stk.pop();
	maxlen = max(maxlen, i - stk.top());
      }
      else
	stk.push(i);
    }

    return maxlen;
  }
};

int main() {

  string str1 = ")()()", str2 = "(()())", str3 = "))))(";
  Solution sol;
  int t1 = sol.longestValidParentheses(str1);
  int t2 = sol.longestValidParentheses(str2);
  int t3 = sol.longestValidParentheses(str3);

  cout << "The longest valid parentheses in " << str1 << " is " << t1 << '\n';
  cout << "The longest valid parentheses in " << str2 << " is " << t2 << '\n';
  cout << "The longest valid parentheses in " << str3 << " is " << t3 << '\n';

  return 0;
}
