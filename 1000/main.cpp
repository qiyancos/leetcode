#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        int k_gap = k - 1;
        if ((n - 1) % k_gap) {
            return -1;
        }
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        vector<int> acc(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
            sum += stones[i];
            acc[i] = sum;
        }
        for (int gap = 2; gap <= n; gap ++) {
            for (int i = 0; i < n - gap + 1; i++) {
           		int end = i + gap - 1;
                for (int split = i; split < end; split += k_gap) {
                    dp[i][end] = min(dp[i][end], dp[i][split] + dp[split + 1][end]);
                }
                if ((gap - 1) % k_gap == 0) {
                    dp[i][end] += acc[end] - (i == 0 ? 0 : acc[i - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    vector<int> stones = {7,7,8,6,5,6,6};
    int K = 3;
    Solution solution;
    cout << solution.mergeStones(stones, K) << endl;
    return 0;
}
