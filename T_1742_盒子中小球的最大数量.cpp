#include<iostream>
#include<unordered_map>
using namespace std;


class Solution 
{
    public:
        int countBalls(int lowLimit, int highLimit) 
        {
            unordered_map<int,int> map(highLimit-lowLimit+1,0);
            int maxNum = 0;
            for(int i = lowLimit; i <= highLimit; i++)
            {
                int index = 0, temp = i;
                while(temp)
                {
                    index += temp % 10;
                    temp /= 10;
                }
                map[index]++;
                maxNum = max(maxNum, map[index]);
            }
            return maxNum;
        }
};

