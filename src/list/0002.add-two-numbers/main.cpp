#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *left{l1}, *right{l2};

        ListNode *head{NULL}, *tail{NULL};
        int shift = 0, sum = 0;
        while(left || right) {
            int a{0}, b{0};
            if (left) {
                a = left->val;
                left = left->next;
            }
            if (right) {
                b = right->val;
                right = right->next;
            }
            sum = a + b + shift;
            ListNode *nd = new ListNode(sum % 10);
            shift = int(sum / 10);
            //std::cout << sum << " " << shift << "| " << a << " " << b << std::endl;


            if (head == NULL) {
                head = nd;
                tail = nd;
                continue;
            }
            
            tail->next = nd;
            tail = tail->next;
        }
        if (shift != 0) {
            tail->next = new ListNode(1);
            tail = tail->next;
        } 
        return head;
    }
};

int main() {
    ListNode l1_0(2), l1_1(4), l1_2(3);
    l1_0.next = &l1_1;
    l1_1.next = &l1_2;

    ListNode l2_0(5), l2_1(6), l2_2(6);
    l2_0.next = &l2_1;
    l2_1.next = &l2_2;

    ListNode *sum = Solution().addTwoNumbers(&l1_0, &l2_0);
    while (sum) {
        std::cout << sum->val << "->";
        sum = sum->next;
    }
    std::cout << std::endl;

    return 0;
}