#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int total_left = 0;
        int total_right = 0;
        for (const auto& num : nums) {
            if (num > k) {
                total_right ++;
            } else if (num < k) {
                total_left ++;
            }
        }
        if (total_right == 0) {
            return 1;
        } else if (total_left == 0) {
            return total_right + 1;
        }
        int result = total_right + 1;
        int left = 1;
        int right = 1;
        int last_left_total = 1;
        int last_right_total = 1;
        while (left <= total_left && right <= total_right) {
            last_left_total = last_left_total * (total_left - left + 1) / left;
            last_right_total = last_right_total * (total_right - right + 1) / right;
            result += last_left_total * last_right_total;
            if (left == right) {
                right ++;
            } else {
                left ++;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {3,2,1,4,5};
    int k = 4;
    Solution solution;
    cout << solution.countSubarrays(nums, k) << endl;
    return 0;
}
