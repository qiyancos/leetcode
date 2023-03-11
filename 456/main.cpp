#include "debug_helper.h"

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int size = nums.size();
        stack<int> down_list;
        down_list.push(nums[size - 1]);
        int max_right = -1e9 -1;
        for (int i = size - 2; i >= 0; i--) {
            if (nums[i] < max_right) {
                return true;
            }
            while (!down_list.empty() && nums[i] > down_list.top()) {
                max_right = down_list.top();
                down_list.pop();
            }
            down_list.push(nums[i]);
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1,0,4,2,-3};
    Solution solution;
    cout << solution.find132pattern(nums) << endl;
    return 0;
}
