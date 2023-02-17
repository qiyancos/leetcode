// 46.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int process_length = -1;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (process_length == -1) {
            process_length = nums.size();
        }
        if (process_length == 1) {
            if (process_length == nums.size()) {
                process_length = -1;
            }
            return { {nums[0]} };
        }
        else {
            process_length--;
            vector<vector<int>> base = this->permute(nums);
            vector<vector<int>> result;
            int target_num = nums[process_length];
            for(auto &base_item : base) {
                for (int insert_index = 0; insert_index <= process_length; insert_index++) {
                    vector<int> temp = base_item;
                    temp.insert(temp.begin() + insert_index, target_num);
                    result.push_back(temp);
                }
            }
            process_length ++;
            if (process_length == nums.size()) {
                process_length = -1;
            }
            return result;
        }
    }
};

int main(){
    vector<int> input = {0,1};
    Solution solution;
    vector<vector<int>> result = solution.permute(input);
    cout << "-----------------------------" << result.size() << "-----------------------------" << endl;
    for (auto item : result) {
        for (auto num : item) {
            cout << num << " ";
        }
        cout << endl;
    }
    vector<int> input_2 = { 0,1,2 };
    result = solution.permute(input_2);
    cout << "-----------------------------" << result.size() << "-----------------------------" << endl;
    for (auto item : result) {
        for (auto num : item) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
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
