#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> n2idx;
        for (auto i = 0; i < nums.size(); i++) {
            n2idx[nums[i]]++;
        }
        int s = 0;
        for (auto &p: n2idx) {
            s += p.second * (p.second - 1) / 2;
        }
        return s;
    }
};

int main() {
    vector<int> nums1 = {1,2,3,1,1,3};
    vector<int> nums2 = {1,1,1,1};
    vector<int> nums3 = {1,2,3};

    std::cout << Solution().numIdenticalPairs(nums1) << std::endl;
    std::cout << Solution().numIdenticalPairs(nums2) << std::endl;
    std::cout << Solution().numIdenticalPairs(nums3) << std::endl;

    return 0;
}