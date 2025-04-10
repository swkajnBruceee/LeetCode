#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> contentMap;

        for (const string& path : paths) {
            // 分割路径字符串为目录和文件列表
            vector<string> parts = split(path);
            if (parts.empty()) continue;
            string directory = parts[0];
            
            for (size_t i = 1; i < parts.size(); ++i) {
                string file = parts[i];
                size_t leftBracket = file.find('(');
                
                // 提取文件名和内容
                string fileName = file.substr(0, leftBracket);
                string content = file.substr(leftBracket + 1, file.size() - leftBracket - 2);
                
                // 构建完整路径并记录到哈希表
                string fullPath = directory + "/" + fileName;
                contentMap[content].push_back(fullPath);
            }
        }

        // 收集所有重复的文件组
        vector<vector<string>> result;
        for (const auto& entry : contentMap) {
            if (entry.second.size() >= 2) {
                result.push_back(entry.second);
            }
        }

        return result;
    }

private:
    // 辅助函数：按空格分割字符串
    vector<string> split(const string& s) {
        vector<string> tokens;
        istringstream iss(s);
        string token;
        while (iss >> token) {
            tokens.push_back(token);
        }
        return tokens;
    }
};