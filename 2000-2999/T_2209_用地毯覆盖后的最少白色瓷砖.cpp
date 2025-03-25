#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        static constexpr int INF = 0x3f3f3f3f;
        int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
            int n = floor.size();
            vector<int> d(n + 1, INF), f(n + 1, INF);
            d[0] = 0;
            for (int i = 1; i <= n; i++) {
                d[i] = d[i - 1] + (floor[i - 1] == '1');
            }
    
            for (int j = 1; j <= numCarpets; j++) {
                f[0] = 0;
                for (int i = 1; i <= n; i++) {
                    f[i] = f[i - 1] + (floor[i - 1] == '1');
                    f[i] = min(f[i], d[max(0, i - carpetLen)]);
                }
                swap(d, f);
            }
    
            return d[n];
        }
    };

