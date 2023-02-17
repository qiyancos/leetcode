// 609.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> content_map;
        for (auto& info: paths) {
            istringstream info_stream(info);
            string dir;
            info_stream >> dir;
            //cout << dir << endl;
            string file_info;
            while (info_stream >> file_info) {
                //cout << file_info << endl;
                int bracket_left = file_info.find('(');
                int bracket_right = file_info.find(')');
                string content = file_info.substr(bracket_left, bracket_right - bracket_left);
                string file_path = dir + "/" + file_info.substr(0, bracket_left);
                if (content_map.find(content) == content_map.end()) {
                    content_map[content] = vector<string>();
                }
                content_map[content].push_back(file_path);
            }
        }
        vector<vector<string>> result;
        for (auto& pair : content_map) {
            if (pair.second.size() > 1) {
                result.push_back(pair.second);
            }
        }
        return result;
    }
};

int main()
{
    vector<string> input = {"root/a 1.txt(abcd) 2.txt(efsfgh)","root/c 3.txt(abdfcd)","root/c/d 4.txt(efggdfh)"};
    Solution solution;
    auto result = solution.findDuplicate(input);
    for (auto& content_list : result) {
        cout << "_____________________" << endl;
        for (auto& file_path : content_list) {
            cout << file_path << endl;
        }
    }
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
