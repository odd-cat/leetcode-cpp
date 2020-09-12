#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
    int searchInsert2(vector<int> &nums, int target) {
        if (nums.empty()) { return -1; }
        if (target <= nums[0]) { return 0; }
        if (target > nums[nums.size()-1]) { return nums.size();}
        int low = 0, high = nums.size() - 1, mid = -1;
        
        while (low < high - 1) {
            //std::cout << low << " " << high << "|" << target << std::endl;
            mid = low + (high - low) / 2;
            //if (high - low == 1 && nums[low] < target && target < nums[high]) {
            //    return high;
            //} 
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                high = std::min(mid, int(nums.size() - 1));
            }
            if (nums[mid] < target) {
                low = std::max(0, mid);
            }
        }

        return high;
    }
    int searchInsert3(vector<int> &nums, int target) {
        int low = 0, high = nums.size(), mid = -1;
        
        while (low < high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid;
            } else {
                low = mid+1;
            }
        }
        return low;
    }
};


int main() {
    vector<int> nums{1,3,5,6};
    for (auto &target: vector<int>{5, 2, 7, 0}) {
        std::cout << Solution().searchInsert3(nums, target) << std::endl;
    }
    return 0;
}