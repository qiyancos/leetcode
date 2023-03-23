#include "debug_helper.h"

using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> result;
        for (int i = 0; i < l.size(); i++) {
            int left = l[i];
            int right = r[i];
            int size = right - left + 1;
            int min = 1e5 + 1;
            int max = -min;
            for (int j = left; j <= right; j++) {
                if (nums[j] > max) {
                    max = nums[j];
                }
                if (nums[j] < min) {
                    min = nums[j];
                }
            }
            if ((max - min) % (size - 1)) {
                result.push_back(false);
                continue;
            }
            bool is_ok = true;
            int gap = (max - min) / (size - 1);
            if (gap) {
                vector<bool> exist(size, false);
                for (int j = left; j <= right; j++) {
                    if ((nums[j] - min) % gap) {
                        is_ok = false;
                        break;
                    }
                    int gap_count = (nums[j] - min) / gap;
                    if (exist[gap_count]) {
                        is_ok = false;
                        break;
                    } else {
                        exist[gap_count] = true;
                    }
                }
            } else {
                for (int j = left; j <= right; j++) {
                    if (nums[j] != min) {
                        is_ok = false;
                        break;
                    }
                }
            }
            result.push_back(is_ok);
        }
        return result;
    }
};

int main() {
    vector<int> nums = {-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10};
    vector<int> l = {0,1,6,4,8,7};
    vector<int> r = {4,4,9,7,9,10};
    Solution solution;
    cout << solution.checkArithmeticSubarrays(nums, l, r) << endl;
    return 0;
}
