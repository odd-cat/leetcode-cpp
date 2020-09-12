#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &nums) {
    std::cout << "[";
    for (auto n: nums) {
        std::cout << n << ", ";
    }
    std::cout << "]" << std::endl;
}

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int tmp = -1;
        for (auto i = 0; i < nums.size(); ++i) {
            while (i != nums[i]) {
                //print(nums);
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                tmp = nums[i];
                nums[i] = nums[nums[i]];
                nums[tmp] = tmp;
            }
            //print(nums);
        }
        return -1;
    }
};

 
int main() {
    Solution solu;
    vector<int> nums{2, 3, 1, 0, 2, 5, 3};
    std::cout << solu.findRepeatNumber(nums) << std::endl;
    return 0;
}