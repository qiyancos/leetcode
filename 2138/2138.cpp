// 2138.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int left_char = s.length();
        while (left_char > 0) {
            string temp = "";
            if (left_char < k) {
                temp = s.substr(s.length() - left_char, left_char);
                temp.append(k - left_char, fill);
            }
            else {
                temp = s.substr(s.length() - left_char, k);
            }
            left_char -= k;
            result.push_back(temp);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string input = "a";
    char fill = 'x';
    vector<string> result = solution.divideString(input, 1, fill);
    for (auto& item : result) {
        std::cout << item << endl;
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
