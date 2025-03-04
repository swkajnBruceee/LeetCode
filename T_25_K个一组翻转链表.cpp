#include<iostream>
#include<utility>
using namespace std;


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
    public:


        pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* last)
        {
            ListNode* pre = last->next; 
            ListNode* next = nullptr;
            ListNode* hea = head;
            while(pre != last)
            {
                next = hea->next;
                hea->next = pre;
                pre = hea;
                hea = next;
            } 
            return {last, head};
        }


        ListNode* reverseKGroup(ListNode* head, int k) 
        {
            ListNode* previous = new ListNode(0);
            previous->next = head;
            ListNode* pre = previous;
            while(head != nullptr)
            {
                ListNode* last = pre;
                for(int i = 0; i < k; i++)
                {
                    last = last->next;
                    if(!last)  // 如果不够K个
                    {
                        return previous->next;
                    }
                }
                ListNode* next = last->next;
                pair<ListNode*, ListNode*> result = myReverse(head, last);
                head = result.first;
                last = result.second;

                pre->next = head;
                last->next = next;
                pre = last;
                head = last->next;

            }
            return previous->next;
        }
};






int main()
{
    ListNode* node = new ListNode(1);
    node->next = new ListNode(2);
    node->next->next = new ListNode(3);
    node->next->next->next = new ListNode(4);
    node->next->next->next->next = new ListNode(5);

    // 记录头节点
    ListNode* head = node;

    cout<<"反转前的链表：";
    while(head != nullptr)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;

    // 反转链表
    Solution solution;
    node = solution.reverseKGroup(node,2);

    cout<<"反转后的链表：";
    while(node != nullptr)
    {
        cout<<node->val<<" ";
        node = node->next;
    }

    return 0;
}



