#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string ret;
        for (auto &ch: s) {
            if (ch != ' ') {
                ret.push_back(ch);
            } else {
                ret += "%20";
            }
        }
        return ret;
    }
    string replaceSpace2(string s) {
        int len = s.size();
        size_t expands = 0;
        for (auto &ch: s) {
            if (ch == ' ') {
                expands++;
            }
        }
        s.resize(s.size() + expands * 2);
        size_t loc = s.size() - 1;
        for (auto i = len - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                s[loc--] = s[i];
            } else {
                s[loc--] = '0';
                s[loc--] = '2';
                s[loc--] = '%';
            }
        }
        return s;
    }
};

int main() {
    std::cout << (Solution().replaceSpace("We are happy.") == "We%20are%20happy.") << std::endl;
    std::cout << (Solution().replaceSpace2("We are happy.") == "We%20are%20happy.") << std::endl;
    return 0;
}