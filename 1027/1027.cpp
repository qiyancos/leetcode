// 1027.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int hash(int index, int delta) {
        int hash_code;
        short* index_p = (short*)&hash_code;
        short* delta_p = index_p + 1;
        *index_p = index;
        *delta_p = delta;
        //cout << "Hash: (" << index << ", " << delta << "): " << hash_code << endl;
        return hash_code;
    }

    int longestArithSeqLength(vector<int>& nums) {
        int max_length = 2;
        // 此处修改hash算法可以将数据结构改为数组，算法速度可以提升
        unordered_map<int, int> dp;
        dp[hash(1, nums[1] - nums[0])] = 2;
        for (int index = 2; index < nums.size(); index++) {
            int num_now = nums[index];
            for (int last_index = index - 1; last_index >= 0; last_index--) {
                int delta = num_now - nums[last_index];
                int new_tag = hash(index,  delta);
                int best_length = dp.find(new_tag) == dp.end() ? 2 : dp[new_tag];
                int old_tag = hash(last_index, delta);
                int last_best_length = dp.find(old_tag) == dp.end() ? 1 : dp[old_tag];
                int new_length = max(best_length, last_best_length + 1);
                dp[new_tag] = new_length;
                //cout << last_index << "->" << index << "(" << delta << ") : " << new_length << endl;
                max_length = max(new_length, max_length);
            }
        }
        return max_length;
    }
};

int main()
{
    vector<int> input = { 9,4,7,2,10 };
    Solution solution;
    std::cout << solution.longestArithSeqLength(input) << endl;
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
