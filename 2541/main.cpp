#include "debug_helper.h"

using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int count = nums1.size();
        if (k == 0) {
            for (int i = 0; i < count; i++) {
                if (nums1[i] != nums2[i]) {
                    return -1;
                }
            }
            return 0;
        }
        long long result = 0;
        long long sub_count_total = 0;
        for (int i = 0; i < count; i ++) {
            int temp = nums1[i] - nums2[i];
            if (temp % k != 0) {
                return -1;
            } else {
                temp /= k;
                sub_count_total += temp;
                result += temp < 0 ? 0 : temp;
            }
        }
        return sub_count_total ? -1 : result;
    }
};

int main() {
    vector<int> nums1 = {3,8,5,2};
    vector<int> nums2 = {2,4,1,6};
    int k = 1;
    Solution solution;
    cout << solution.minOperations(nums1, nums2, k) << endl;
    return 0;
}
