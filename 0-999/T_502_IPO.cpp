#include <iostream>
#include <queue>
using namespace std;

class Solution {
    public:
        
        // 定义节点结构体
        struct Node 
        {
            int p;  // 利润
            int c;  // 成本
            Node(int x, int y) : p(x), c(y) {}
        };
    
        // 比较器：成本小的节点排在前面（用于小根堆）
        struct MinCostComparator 
        {
            bool operator()(const Node& a, const Node& b) 
            {
                return a.c > b.c;
            }
        };
    
        // 比较器：利润大的节点排在前面（用于大根堆）
        struct MaxProfitComparator 
        {
            bool operator()(const Node& a, const Node& b) 
            {
                return a.p < b.p;
            }
        };
        
        
        int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
        {
            priority_queue<Node, vector<Node>, MinCostComparator> minCostQ;
            priority_queue<Node, vector<Node>, MaxProfitComparator> maxProfitQ;
    
            // 将所有项目放入成本小根堆中
            for (int i = 0; i < (int)profits.size(); i++) 
            {
                minCostQ.push(Node(profits[i], capital[i]));
            }
    
            for (int i = 0; i < k; i++) 
            {  
                // 进行 K 轮,将能力所及的项目放入利润大根堆中
                while (!minCostQ.empty() && minCostQ.top().c <= w) 
                {
                    maxProfitQ.push(minCostQ.top());
                    minCostQ.pop();
                }
    
                if (maxProfitQ.empty()) return w;
                w += maxProfitQ.top().p;
                maxProfitQ.pop();
            }
    
            return w;
        }
    };