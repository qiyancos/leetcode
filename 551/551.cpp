// 551.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int L_count = 0;
        int A_count = 0;
        for (auto& day : s) {
            if (day == 'L') {
                L_count += 1;
                if (L_count > 2) {
                    return false;
                }
            } else {
                L_count = 0;
                if (day == 'A') {
                    A_count++;
                    if (A_count > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution  solution;
    std::cout << solution.checkRecord("AA") << endl;
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
