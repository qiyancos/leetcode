#include "debug_helper.h"

using namespace std;

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> new_arr;
        for (int i = 0; i < nums.size(); ++i) {
            new_arr.insert(new_arr.begin() + index[i], nums[i]);
        }
        return new_arr;
    }
};

int main() {
    vector<int> nums = {0,1,2,3,4};
    vector<int> index = {0,1,2,2,1};
    Solution solution;
    cout << solution.createTargetArray(nums, index) << endl;
    return 0;
}
