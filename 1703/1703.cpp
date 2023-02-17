// 1703.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        if (k == 1) {
            return 0;
        }
        int mid = k >> 1;
        int gap = k - 1;
        vector<int> indexes;
        for (int index = 0; index < nums.size();index++) {
            if (nums[index]) {
                indexes.push_back(index);
                cout << index << " ";
            }
        }
        cout << endl;
        // 计算第一个中位数加和
        int min_op = 0;
        for (int index = 0; index < k; index++) {
            min_op += abs(indexes[index] - indexes[k >> 1]);
        }
        cout << min_op << " ";
        int last_op = min_op;
        for (int index = 1; index < indexes.size() - k + 1;index++) {
            int new_op = 0;
            if (k == 2) {
                new_op = indexes[index + 1] - indexes[index];
            }
            else {
                new_op = last_op + (indexes[index + gap] - indexes[index + gap - mid]) -
                    (indexes[index - 1 + mid] - indexes[index - 1]);
            }
            cout << new_op << " ";
            min_op = min(new_op, min_op);
            last_op = new_op;
        }
        cout << endl;
        return k == 2 ? min_op -1 : min_op - mid  * (mid + (k & 1 ?1 : 0));
    }
};

int main()
{
    vector<int> input = { 1,0,1,0,1,1,0,1,1,1,1,1,0,1,0,1,1,0,1,0,0,1,1,1 };
    Solution solution;
    std::cout << solution.minMoves(input, 12) << endl;
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
