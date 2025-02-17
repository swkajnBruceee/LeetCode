#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution 
{
    public:
        int findSpecialInteger(vector<int>& arr) 
        {
            int n = arr.size();
            unordered_map<int,int> map(n,0);
            for(int i = 0; i < n; i++)
            {
                if(!map.count(arr[i])) map.emplace(arr[i],1);
                else map[arr[i]]++;
                
                if(map[arr[i]]*4 > n) return arr[i];
            }
            return -1;
        }
};


