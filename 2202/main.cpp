#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1 && k & 1) {
            return -1;
        }
        if (k > n) {
            k = n + 1;
        }
        int result = 0;
        for (int i = 0; i < k - 1; i++) {
            result = max(nums[i], result);
        }
        if (k < n) {
            result = max(nums[k], result);
        }
        return result;
    }
};

int main() {
    vector<int> nums = {5,2,2,9,0,6};
    int k = 3;
    Solution solution;
    cout << solution.maximumTop(nums, k) << endl;
    return 0;
}
