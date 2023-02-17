#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int total = 0;
        int last_num = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= last_num) {
                total += last_num - nums[i] + 1;
                last_num = last_num + 1;
            } else {
                last_num = nums[i];
            }
        }
        return total;
    }
};

int main() {
    vector<int> nums = {1,5,2,4,1};
    Solution solution;
    cout << solution.minOperations(nums) << endl;
    return 0;
}
