#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> ab_sum_count;
        for (const auto num1 : nums1) {
            for (const auto num2 : nums2) {
                int sum = num1 + num2;
                ab_sum_count[sum] ++;
                /*
                if (ab_sum_count.find(sum) == ab_sum_count.end()) {
                    ab_sum_count[sum] = 1;
                } else {
                    ab_sum_count[sum] ++;
                }
                */
            }
        }
        int total = 0;
        for (const auto num3 : nums3) {
            for (const auto num4 : nums4) {
                int sum = 0 - num3 - num4;
                total += ab_sum_count[sum];
                /*
                if (ab_sum_count.find(sum) != ab_sum_count.end()) {
                    total += ab_sum_count[sum];
                }
                */
            }
        }
        return total;
    }
};

int main() {
	vector<int> nums1 = {1,2};
	vector<int> nums2 = {-2,-1};
    vector<int> nums3 = {-1,2};
    vector<int> nums4 = {0,2};
    Solution solution;
    cout << solution.fourSumCount(nums1, nums2, nums3, nums4) << endl;
    return 0;
}
