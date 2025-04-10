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
            // �ָ�·���ַ���ΪĿ¼���ļ��б�
            vector<string> parts = split(path);
            if (parts.empty()) continue;
            string directory = parts[0];
            
            for (size_t i = 1; i < parts.size(); ++i) {
                string file = parts[i];
                size_t leftBracket = file.find('(');
                
                // ��ȡ�ļ���������
                string fileName = file.substr(0, leftBracket);
                string content = file.substr(leftBracket + 1, file.size() - leftBracket - 2);
                
                // ��������·������¼����ϣ��
                string fullPath = directory + "/" + fileName;
                contentMap[content].push_back(fullPath);
            }
        }

        // �ռ������ظ����ļ���
        vector<vector<string>> result;
        for (const auto& entry : contentMap) {
            if (entry.second.size() >= 2) {
                result.push_back(entry.second);
            }
        }

        return result;
    }

private:
    // �������������ո�ָ��ַ���
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