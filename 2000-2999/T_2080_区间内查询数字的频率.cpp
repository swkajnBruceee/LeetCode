#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class RangeFreqQuery 
{
    private: 
        // ��ֵΪ���������±�����Ϊֵ�Ĺ�ϣ��
        unordered_map<int, vector<int>> map;
        
    public:
        RangeFreqQuery(vector<int>& arr) 
        {
            // ˳����������ʼ����ϣ��
            int n = arr.size();
            for (int i = 0; i < n; ++i){
                map[arr[i]].push_back(i);
            }
        }
        
        int query(int left, int right, int value) 
        {
            // ���Ҷ�Ӧ�ĳ����±����飬��������Ϊ��
            const vector<int>& pos = map[value];
            // ���ζ��ֲ��Ҽ����������ڳ��ִ���
            auto l = lower_bound(pos.begin(), pos.end(), left);
            auto r = upper_bound(pos.begin(), pos.end(), right);
            return r - l;
        }
};
    
/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
