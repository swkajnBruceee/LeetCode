#include<iostream>
#include<queue>
#include<vector>
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
        ListNode* mergeKLists(vector<ListNode*>& lists) 
        {
            priority_queue<int, vector<int>, greater<int>> que;
            for(int i = 0; i < (int)lists.size();i++)
            {
                ListNode* root = lists[i];
                while(root != nullptr)
                {
                    que.push(root->val);
                    root = root->next;
                }
            }
            ListNode* head = new ListNode();
            ListNode* cur = head;
            while(!que.empty())
            {
                cur->next = new ListNode(que.top());
                que.pop();
                cur = cur->next;
            }
            return head->next;
        }
};


int main()
{

    return 0;
}




