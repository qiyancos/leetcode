﻿// 495.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (duration == 0) {
            return 0;
        }
        int start_time = timeSeries[0];
        int end_time = timeSeries[0] + duration;
        int total = 0;
        int index = 1;
        while (index < timeSeries.size()) {
            if (timeSeries[index] > end_time) {
                total += end_time - start_time;
                start_time = timeSeries[index];
                end_time = start_time + duration;
            }
            else {
                end_time = timeSeries[index] + duration;
            }
            index++;
        }
        total += end_time - start_time;
        return total;
    }
};
int main()
{
    vector<int> input = {1,1};
    int duration = 3;
    Solution solution;
    std::cout << solution.findPoisonedDuration(input, duration) << endl;
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
