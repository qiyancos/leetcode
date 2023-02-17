#include "debug_helper.h"

using namespace std;

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0] == 1 ? true : false;
        } else {
            int last_gcd = nums[0];
            for(int i = 1; i < nums.size();i++) {
                int num_now = nums[i];
                while(true) {
                    int max_num = max(num_now, last_gcd);
                    int min_num = min(num_now, last_gcd);
                    last_gcd = max_num % min_num;
                    if (last_gcd == 0) {
                        last_gcd = min_num;
                        break;
                    }
                    num_now = min_num;
                }
                if (last_gcd == 1) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {18,9,12,18,12,30,15,18,21,21,15,24,6,12,27,27,6,18,30,3,8};
    Solution solution;
    cout << solution.isGoodArray(nums) << endl;
    return 0;
}
