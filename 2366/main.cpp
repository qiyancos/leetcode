#include "debug_helper.h"

using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        int last_min = nums[n - 1];
        int result = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= last_min) {
                last_min = nums[i];
            } else {
                int times = (nums[i] - 1) / last_min;
                result += times++;
                last_min = nums[i] / times;
                // cout << last_min << ":" << times << endl;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {3,9,3};
    Solution solution;
    cout << solution.minimumReplacement(nums) << endl;
    return 0;
}
