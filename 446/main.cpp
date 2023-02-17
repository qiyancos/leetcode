#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count = nums.size();
        if (count < 3) {
            return 0;
        }
        int total = 0;
        vector<map<long long, int>> dp(count, map<long long, int>());
        dp[1][(long long)nums[1] - nums[0]] = 1;
        for (int i = 2; i < count; i++) {
            for (int j = i - 1; j >= 0; j--) {
                long long gap = (long long)(nums[i]) - nums[j];
                if (dp[i].find(gap) == dp[i].end()) {
                    dp[i][gap] = 0;
                }
                dp[i][gap] += 1;
                if (dp[j].find(gap) != dp[j].end()) {
                    total += dp[j][gap];
                    dp[i][gap] += dp[j][gap];
                }
            }
            // cout << total << ":" << dp << endl;
        }
        return total;
    }
};

int main() {
    // vector<int> nums = {2,4,6,8,13};
    // vector<int> nums = {1,1,1,1,1};
    vector<int> nums = {0,2000000000,-294967296};
    Solution solution;
    cout << solution.numberOfArithmeticSlices(nums) << endl;
    return 0;
}
