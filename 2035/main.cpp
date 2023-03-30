#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() >> 1;
        vector<vector<int>> left_value(n + 1, vector<int>());
        vector<vector<int>> right_value(n + 1, vector<int>());
        for (int i = 0; i < (1 << n); i++) {
            int cnt = 0;
            int left_sum = 0;
            int right_sum = 0;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    cnt++;
                    left_sum += nums[j];
                    right_sum += nums[j + n];
                } else {
                    left_sum -= nums[j];
                    right_sum -= nums[j + n];
                }
            }
            left_value[cnt].push_back(left_sum);
            right_value[cnt].push_back(right_sum);
        }
        for (int i = 0; i <= n; i++) {
            sort(left_value[i].begin(), left_value[i].end());
            sort(right_value[i].begin(), right_value[i].end());
        }
        //cout << left_value << endl;
        //cout << right_value << endl;
        int min_gap = 2e9;
        for (int lcnt = 0; lcnt <= n; lcnt++) {
            int rcnt = n - lcnt;
            for (int j = left_value[lcnt].size() - 1, k = 0; j >= 0; j--) {
                while (k < right_value[rcnt].size() && left_value[lcnt][j] + right_value[rcnt][k] < 0) {
                    k++;
                }
                if (k < right_value[rcnt].size()) {
                    min_gap = min(min_gap, abs(left_value[lcnt][j] + right_value[rcnt][k]));
                }
                if (k - 1 >= 0) {
                    min_gap = min(min_gap, abs(left_value[lcnt][j] + right_value[rcnt][k - 1]));
                }
            }
        }
        return min_gap;
    }
};

int main() {
    vector<int> nums = {3,9,7,3};
    Solution solution;
    cout << solution.minimumDifference(nums) << endl;
    return 0;
}
