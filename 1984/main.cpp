#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int result = nums.back() - nums[0] + 1;
        for (int i = 0; i <= nums.size() - k; i++) {
            result = min(result, nums[i + k - 1] - nums[i]);
        }
        return result;
    }
};

int main() {
    vector<int> nums = {9,4,1,7};
    int k = 2;
    Solution solution;
    cout << solution.minimumDifference(nums, k) << endl;
    return 0;
}
