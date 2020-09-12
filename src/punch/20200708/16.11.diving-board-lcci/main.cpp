#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if (k == 0) {
            return {};
        }
        if (shorter == longer) {
            return {k * shorter};
        }
        vector<int> ret;
        for (auto i = 0; i <= k; ++i) {
            ret.push_back(shorter * k + (longer - shorter) * i);
        }
        return ret;
    }
};

void print(vector<int> &&nums) {
    if (nums.empty()) {
        std::cout << "[]" << std::endl;
        return;
    }
    std::cout << "[";
    for (auto i = 0; i < nums.size() - 1; ++i) {
        std::cout << nums[i] << ", ";
    }
    std::cout << nums[nums.size() - 1] << "]" << std::endl;
}

int main() {
    print(Solution().divingBoard(1, 2, 3));
    return 0;
}