// 1049.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum_w = accumulate(stones.begin(), stones.end(), 0);
        vector<int> dp((sum_w >> 1) + 1, 0);
        for (auto& stone : stones) {
            for (int weight = dp.size() - 1; weight >= stone; weight--) {
                dp[weight] = max(dp[weight], dp[weight - stone] + stone);
            }
        }
        return sum_w - (dp.back() << 1);
    }
};

int main()
{
    vector<int> input = { 2,2,4 };
    Solution solution;
    std::cout << solution.lastStoneWeightII(input) << endl;
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
