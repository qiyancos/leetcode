// 面试题1615.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        int index = 3;
        int total_guess = 0;
        vector<int> solution_color(256, 0);
        vector<int> guess_color(256, 0);
        while (index >= 0) {
            if (solution[index] == guess[index]) {
                total_guess += 1;
            }
            else {
                solution_color[solution[index]] ++;
                guess_color[guess[index]] ++;
            }
            index--;
        }
        int part_guess = 0;
        for (auto key : { 'R', 'G','B','Y' }) {
            part_guess += min(solution_color[key], guess_color[key]);
        }
        return { total_guess, part_guess };
    }
};

int main()
{
    Solution solution;
    vector<int> result = solution.masterMind("RRGG", "GGRR");
    cout << result[0] << " " << result[1] << endl;
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
