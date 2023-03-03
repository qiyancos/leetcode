#include "debug_helper.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target + 1);
        dp[0] = {{}};
        for(auto&& i: candidates) {
            for(int j = i; j <= target; j ++) {
                for(auto& k: dp[j - i]) {
                    dp[j].emplace_back(k).emplace_back(i);
                }
            }
        }
        return dp[target];
    }
};

int main() {
	vector<int> candidates = {2,3,6,7};
	int target = 7;
    Solution solution;
    cout << solution.combinationSum(candidates, target) << endl;
    return 0;
}
