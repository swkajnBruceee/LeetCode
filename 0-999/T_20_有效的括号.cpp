#include<iostream>
#include<string>  
#include<unordered_map>
#include<stack>            
using namespace std;

class Solution 
{
    public:
        bool isValid(string s) 
        {
            int n = s.size();
            if (n % 2 == 1) 
            {
                return false;
            }

            unordered_map<char, char> pairs = 
            {
                {')', '('},
                {']', '['},
                {'}', '{'}
            };
            stack<char> stk;
            for (char ch: s) 
            {
                if (pairs.count(ch)) 
                {
                    if (stk.empty() || stk.top() != pairs[ch]) 
                    {
                        return false;
                    }
                    stk.pop();
                }
                else 
                {
                    stk.push(ch); //��� ch �������ţ�����ѹ��ջ��
                }
            }
        return stk.empty();//�������������ջΪ�գ���˵�����е����Ŷ�ƥ��ɹ�
    }
};

int main()
{
    string s = "{({[(]})}";
    Solution solution; // ���� Solution ���ʵ��
    bool result = solution.isValid(s); // ͨ��ʵ������ isValid ����
    cout << (result ? "��Ч" : "��Ч") << endl; // ������
    return 0;
}



/*
�ж����ŵ���Ч�Կ���ʹ�á�ջ����һ���ݽṹ�������

���Ǳ����������ַ��� s������������һ��������ʱ�����ǻ������ں����ı����У���һ����ͬ���͵������Ž���պϡ����ں�������������Ҫ�ȱպϣ�������ǿ��Խ���������ŷ���ջ����

����������һ��������ʱ��������Ҫ��һ����ͬ���͵������űպϡ���ʱ�����ǿ���ȡ��ջ���������Ų��ж������Ƿ�����ͬ���͵����š����������ͬ�����ͣ�����ջ�в�û�������ţ���ô�ַ��� s ��Ч������ False��Ϊ�˿����ж����ŵ����ͣ����ǿ���ʹ�ù�ϣ��洢ÿһ�����š���ϣ��ļ�Ϊ�����ţ�ֵΪ��ͬ���͵������š�

�ڱ������������ջ��û�������ţ�˵�����ǽ��ַ��� s �е����������űպϣ����� True�����򷵻� False��

ע�⵽��Ч�ַ����ĳ���һ��Ϊż�����������ַ����ĳ���Ϊ���������ǿ���ֱ�ӷ��� False��ʡȥ�����ı����жϹ��̡�
*/




