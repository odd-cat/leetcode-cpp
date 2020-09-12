#include <iostream>
#include <stack>
#include <string>

using std::string;

class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) {
            return true;
        }
        std::stack<char> parentheses;
        char top;
        for (auto ch: s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                parentheses.push(ch);
                continue;
            }
            if (parentheses.empty()) {
                return false;
            }
            top = parentheses.top();
            if ((ch == ')' && top == '(') || 
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                parentheses.pop();
            } else {
                return false;
            }
        }
        return parentheses.empty();
    }
};

int main() {
    Solution solu;
    std::cout << solu.isValid("()") << std::endl;
    std::cout << solu.isValid("()[]{}") << std::endl;
    std::cout << solu.isValid("(]") << std::endl;
    std::cout << solu.isValid("([)]") << std::endl;
    std::cout << solu.isValid("{[]}") << std::endl;
    std::cout << solu.isValid("(])") << std::endl;
}