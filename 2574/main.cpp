#include "debug_helper.h"

using namespace std;

class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            sum += nums[i];
        }
        vector<int> result(n, 0);
        result[0] = sum;
        for (int i = 1; i < n; i++) {
            sum -= nums[i] + nums[i - 1];
            result[i] = abs(sum);
        }
        return result;
    }
};

int main() {
	vector<int> nums = {1};
    Solution solution;
    cout << solution.leftRigthDifference(nums) << endl;
    return 0;
}
