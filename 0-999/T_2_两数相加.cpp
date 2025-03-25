#include<iostream>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        ListNode* root = l3;

        int temp = 0;
        while(l1 != nullptr || l2 != nullptr)
        {
            int a = l1 == nullptr ? 0 : l1->val;
            int b = l2 == nullptr ? 0 : l2->val;
            temp += a + b;
            l3->val = temp % 10;
            temp /= 10;
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
            if(l1 != nullptr || l2 != nullptr) //避免了在两个链表长度相等时总是输出结果最后多一个 0 的问题
            {
                l3->next = new ListNode();
                l3 = l3->next;
            }
        }
        if(temp == 1)
        {
            l3->next = new ListNode(1);
        }
        return root;
    }
};







