#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            int left = nums[i] % p;
            nums[i] = left;
            total = (total + left) % p;
        }
        if (total == 0) {
            return 0;
        }
    	unordered_map<int,int> pos;
        pos[0]=-1;
        int sum = 0;
        int res = 0;
        int ans = nums.size();
        for(int i=0;i<nums.size();++i)
        {
            sum=(sum+nums[i])%p;
            res=(sum-total+p)%p;//计算前缀和，以及要查找的和
            pos[sum]=i;//记录这个前缀和
            ans=min(ans, pos.find(res)==pos.end() ? int(nums.size()) : i - pos[res]);//查找并比较
        }
        return ans==nums.size()?-1:ans;
	}
};

int main() {
    vector<int> input = {26,19,11,14,18,4,7,1,30,23,19,8,10,6,26,3};
    int p = 26;
    Solution solution;
    cout << solution.minSubarray(input, p) << endl;
    return 0;
}
