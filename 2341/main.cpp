#include "debug_helper.h"

using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int total = int(nums.size());
        if (total == 1) {
            return {0, 1}; 
        } else {
            vector<int> counts(101, 0);
            for (const auto& num : nums) {
                counts[num] ++; 
            }   
            int pair_count = 0;
            int left_nums = 0;
            for (const auto& count : counts) {
                pair_count += (count & 0xfffffffe);
            }   
            return {pair_count >> 1, total - pair_count};
        }   
    }   
};

int main() {
    vector<int> nums = {1,3,4,1,3,2,2};
    Solution solution;
    cout << solution.numberOfPairs(nums) << endl;
    return 0;
}
