#include "debug_helper.h"

using namespace std;

struct DP {
    int dp = 0;
    // 以当前节点为结尾的工作起点和Profit
    vector<pair<int, int>> lines;
};

class Solution1 {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int count = startTime.size();
        unordered_map<int, DP> dp;
        vector<int> end_sorted = endTime;
        sort(end_sorted.begin(), end_sorted.end());
        for (int i = 0; i < count; i++) {
            pair<int, int> work_info = {startTime[i], profit[i]};
            if (dp.find(endTime[i]) == dp.end()) {
                dp[endTime[i]] = DP();
            }
            dp[endTime[i]].dp = max(dp[endTime[i]].dp, profit[i]);
            dp[endTime[i]].lines.push_back(work_info);
        }
        int max_profit = 0;
        for (int i = 0; i < count; i++) {
            int end = end_sorted[i];
            for (const auto line : dp[end].lines) {
                for (int j = i - 1; j >= 0; j--) {
                    int test_end = end_sorted[j];
                    if (test_end > line.first) continue;
                    dp[end].dp = max(dp[end].dp, dp[test_end].dp + line.second);
                }
            }
            max_profit = max(max_profit, dp[end].dp);
            //cout << end << ":" << dp[end].dp << endl;
        }
        return max_profit;
    }
};

int main() {
    //vector<int> start_time = {1,2,3,4,6};
    //vector<int> end_time = {3,5,10,6,9};
    //vector<int> profit = {20,20,100,70,60};
    vector<int> start_time = {1,2,3,3};
    vector<int> end_time = {3,4,5,6};
    vector<int> profit = {50,10,40,70};
    Solution solution;
    cout << solution.jobScheduling(start_time, end_time, profit) << endl;
    return 0;
}
