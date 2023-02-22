#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int count = startTime.size();
        vector<int> dp(count, 0);
        vector<vector<int>> work;
        for (int i = 0; i < count; i++) {
            work.push_back(vector<int>({startTime[i], endTime[i], profit[i]}));
        }
        sort(work.begin(), work.end(), [](const vector<int>& a, const vector<int>& b) ->bool{return a[1] < b[1];});
        cout << work << endl;
        for (int i = 0; i < count; i++) {
            dp[i] = work[i][2];
            for(int j = i - 1; j >= 0; j--) {
                if (work[j][1] > work[i][0]) {
                    dp[i] = max(dp[i], dp[j]);
                } else {
                    dp[i] = max(dp[i], dp[j] + work[i][2]);
                    break;
                }
            }
            cout << dp << endl;
        }
        return dp[count - 1];
    }
};

int main() {
    vector<int> start_time = {1,2,3,4,6};
    vector<int> end_time = {3,5,10,6,9};
    vector<int> profit = {20,20,100,70,60};
    //vector<int> start_time = {1,2,3,3};
    //vector<int> end_time = {3,4,5,6};
    //vector<int> profit = {50,10,40,70};
    Solution solution;
    cout << solution.jobScheduling(start_time, end_time, profit) << endl;
    return 0;
}
