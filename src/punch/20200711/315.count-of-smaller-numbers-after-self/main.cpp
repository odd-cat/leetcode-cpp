#include <iostream>
#include <vector>

using namespace std;

class Solution {
    struct Node {
        int val;
        int count;
        Node *left, *right;
        Node(int val_): val(val_), count(0), left(NULL), right(NULL) {}
    };
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<int> counts(nums.size());
        Node *root = NULL;
        for (auto i = 0; i < nums.size() ; ++i) {
            //std::cout << nums[nums.size() - 1 - i] << " ";
            counts[nums.size() - 1 - i] = insert(root, nums[nums.size() - 1 - i]);
        }
        return counts;
    }
    int insert(Node *&root, int val) {
        if (root == NULL) {
            root = new Node(val);
            return 0;
        }
        if (val > root->val) {
            int count = insert(root->right, val);
            return root->count + 1 + count;
        } else {
            int count = insert(root->left, val);
            root->count++;
            return count;
        }
    }
};

void print(const vector<int> &&nums) {
    for (const auto &n: nums) {
        std::cout << n << ", ";
    }
    std::cout << std::endl;
}
int main() {
    vector<int> nums{5,2,6,1};
    print(Solution().countSmaller(nums));
    vector<int> nums1{1,3,6,1,2,3};
    print(Solution().countSmaller(nums1));
    vector<int> nums2{26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
    print(Solution().countSmaller(nums2));
    
    return 0;
}