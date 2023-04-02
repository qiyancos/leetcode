#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<int> acc(n, 1);
        for (int i = 1; i < n; i++) {
            acc[i] = values[i] * values[i -1];
        }
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        for (int gap = 2; gap < n; gap++) {
            for (int i = 0; i < n - gap; i++) {
                if (gap == 2) {
                    dp[i][i + 2] = acc[i + 1] * values[i + 2];
                } else {
                    dp[i][i + gap] = min(dp[i + 1][i + gap] + acc[i + 1] * values[i + gap],
                                         dp[i][i + gap - 1] + acc[i + gap] * values[i]);
                    for (int mid = i + 2; mid < i + gap - 1; mid++) {
                        dp[i][i + gap] = min(dp[i][i + gap], dp[i][mid] + dp[mid][i + gap] + 
                                values[i] * values[mid] * values[i + gap]);
                    }
                }
                // cout << i << "-" << i + gap << ":" << dp[i][i + gap] << endl;
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    vector<int> input = {1,3,1,4,1,5};
    Solution solution;
    cout << solution.minScoreTriangulation(input) << endl;
    return 0;
}
