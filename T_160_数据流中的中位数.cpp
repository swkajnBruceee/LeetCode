#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class MedianFinder {
    public:
        /** initialize your data structure here. */
        priority_queue<int, vector<int>, greater<int>> small_q;
        priority_queue<int, vector<int>> big_q;
        MedianFinder() {}
        void addNum(int num) 
        {
            if(big_q.empty() || num <= big_q.top()) big_q.push(num);
            else small_q.push(num);

            if(big_q.size() >= small_q.size() + 2)
            {               
                small_q.push(big_q.top());
                big_q.pop();
            }
            else if(small_q.size() >= big_q.size() + 2)
            {
                big_q.push(small_q.top());
                small_q.pop();
            }
        }
        
        double findMedian() 
        {
            if (big_q.size() > small_q.size()) {
                return big_q.top();
            } 
            else if (small_q.size() > big_q.size()) {
                return small_q.top();
            } 
            else {
                return (big_q.top() + small_q.top()) / 2.0;
            }
        }
    };
    
    /**
     * Your MedianFinder object will be instantiated and called as such:
     * MedianFinder* obj = new MedianFinder();
     * obj->addNum(num);
     * double param_2 = obj->findMedian();
     */




