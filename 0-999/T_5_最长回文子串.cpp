#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution 
{
    public:
        
   
        string longestPalindrome(string s) 
        {
            int len = s.size();
            if(len < 2) return s;
            
            int maxLen = 1;
            int begin = 0;
            // dp[i][j] ��ʾ s[i..j] �Ƿ��ǻ��Ĵ�
            vector<vector<int>> dp(len, vector<int>(len));
            for(int i = 0; i < len; i++)
            {
                dp[i][i] = true;
            }
            for(int L = 2; L <= len; L++)
            {
                for(int i = 0; i < len; i++)
                {
                    int j = L + i -1;
                    if(j >= len) break;
                    if(s[i] != s[j]) dp[i][j] = false;
                    else
                    {
                        if(j - i < 3) dp[i][j] = true;
                        else dp[i][j] = dp[i+1][j-1];
                    }
                    if(dp[i][j] && j-i+1 > maxLen)
                    {
                        maxLen = j - i + 1;
                        begin = i;
                    }
                }
            }
            return s.substr(begin, maxLen);
        }
};

int main()
{
    string s1 = "babad";
    Solution solution;
    string s = solution.longestPalindrome(s1);
    cout<<"������Ӵ��ǣ�"<<s;
    return 0;
}

