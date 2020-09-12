#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        
        ListNode *tmp = head;
        int N = 0;
        while (tmp) {
            N++;
            tmp = tmp->next;
        }
        vector<int> nums(N);
        tmp = head;
        for (auto it = nums.rbegin(); it != nums.rend(); it++) {
            *it = tmp->val;
            tmp = tmp->next;
        }
        return nums;
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
    ListNode nd1(1), nd2(3), nd3(2);
    nd1.next = &nd2;
    nd2.next = &nd3;

    print(Solution().reversePrint(&nd1));
    return 0;
}