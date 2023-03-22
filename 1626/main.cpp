#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>> score_age;
        for (int i = 0; i < scores.size(); i++) {
            score_age.push_back(vector<int>({scores[i], ages[i]}));
        }
        sort(score_age.begin(), score_age.end(),
                [](const vector<int>& a, const vector<int>& b) -> bool {return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];});
        unordered_map<int, int> dp;
        dp[0] = 0;
        int result = 0;
        for (const auto crew : score_age) {
            int max_sum = 0;
            for (const auto& dp_info : dp) {
                int dp_score = dp_info.first;
                if (dp_score <= crew[0]) {
                    max_sum = max(max_sum, dp_info.second);
                }
            }
            dp[crew[0]] = max_sum + crew[0];
            result = max(dp[crew[0]], result);
            // cout << crew << ": " << dp << endl;
        }
        return result;
    }
};

int main() {
    vector<int> scores = {1,2,3,5};
    vector<int> ages = {8,9,10,1};
    Solution solution;
    cout << solution.bestTeamScore(scores, ages) << endl;
    return 0;
}
