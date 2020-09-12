#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numSub(string s) {
        vector<long long> lens;
        int i = 0;
        while (i < s.length()) {
            if (s[i] == '1') {
                int j = i+1;
                while (j < s.length() && s[j] == '1') { j++; }
                lens.push_back(j - i);
                i = j;
            } else {
                i++;
            }
        }
        int total = 0;
        for (auto &len: lens) {
            long long tmp = (total + len * (len + 1) / 2) % (1000000007);
            total = tmp;
        }
        return total;
    }
};

int main() {
    std::cout << Solution().numSub("0110111") << std::endl;
    std::cout << Solution().numSub("101") << std::endl;
    std::cout << Solution().numSub("111111") << std::endl;
    std::cout << Solution().numSub("000") << std::endl;
    return 0;
}