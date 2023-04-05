#include "debug_helper.h"

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                result.push_back(i);
            } else if (nums[i] > target) {
                break;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {1,2,5,2,3};
    int target = 2;
    Solution solution;
    cout << solution.targetIndices(nums, target) << endl;
    return 0;
}
