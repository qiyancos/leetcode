#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int min = nums[0];
        int result = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - min > k) {
                min = nums[i];
                result += 1;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {2,2,3,4};
    int k = 0;
    Solution solution;
    cout << solution.partitionArray(nums, k) << endl;
    return 0;
}
