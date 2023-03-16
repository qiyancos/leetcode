#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int sum = 0, res = 0;
        bool flag = false;
        for(auto&& num : nums){
            sum += num >= k ? (num == k ? 0 : 1) : -1;
            if(flag || num == k){
                flag = true;
                res += cnt[sum] + cnt[sum-1];
            }
            else
                cnt[sum]++;
        }
        return res;
    }
};

int main() {
    vector<int> nums = {2,5,1,4,3,6};
    int k = 1;
    Solution solution;
    cout << solution.countSubarrays(nums, k) << endl;
    return 0;
}
