#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int count = piles.size();
        if (count == 1) {
            return piles[0];
        }
        vector<vector<int>> dp(count, vector<int>(count + 1, 0));
        vector<int> sum(count + 1, 0);
        for (int M = 1; M <= count; M++) {
            dp[count - 1][M] = piles[count - 1];
        }
        for (int i = count - 1; i >= 0; i--) {
            sum[i] = piles[i] + sum[i + 1];
        }
        for (int M = count; M > 0; M--) {
            int M2 = M << 1;
            for (int i = count - 2; i >= 0; i--) {
                if (count - i <= M2) {
                    dp[i][M] = sum[i];
                } else {
                    for (int pick = 1; pick <= M2; pick++) {
                        dp[i][M] = max(dp[i][M], sum[i] - dp[i + pick][max(M, pick)]);
                    }
                }
            }
        }
        // cout << dp << endl;
        return dp[0][1];
    }
};

int main() {
    // vector<int> piles = {2,7,9,4,4};
    vector<int> piles = {1,2,3,4,5,100};
    Solution solution;
    cout << solution.stoneGameII(piles) << endl;
    return 0;
}
