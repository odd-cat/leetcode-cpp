#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> exists;
        for (auto i =0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (exists.find(diff) != exists.end()) {
                return {exists[diff], i};
            }
            exists[nums[i]] = i;
        }
        return {};
    }
};

void print(vector<int> &&ans) {
    std::cout << "[" << ans[0] << ", " << ans[1] << "]" << std::endl;
}
int main() {
    vector<int> nums{2, 7, 11, 15};
    int target{9};

    print(Solution().twoSum(nums, target));
    return 0;
}