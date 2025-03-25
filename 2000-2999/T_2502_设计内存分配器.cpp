#include<iostream>
#include<vector>
using namespace std;


class Allocator 
{
    vector<int> memory;
    public:
        Allocator(int n) : memory(n){}

        
        int allocate(int size, int mID) 
        {
            int flag = 0;
            for(int i = 0; i < (int)memory.size(); i++)
            {
                if(memory[i] > 0)
                {
                    flag = 0;
                    continue;
                }
                flag++;

                if(flag == size)
                {
                    // fill(first, last, value) 包含first，不包含last
                    fill(memory.begin()+i-size+1, memory.begin()+i+1, mID);
                    return i-size+1;
                }

            }
            return -1;
        }
        
        int freeMemory(int mID) 
        {
            int count = 0;
            for (int i = 0; i < memory.size(); i++) 
            {
                if (memory[i] == mID)
                {
                    memory[i] = 0; // 标记为空闲内存
                    count++;
                }
            }
            return count;
        }
};
    
/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */







