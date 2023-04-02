#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int p1 = 0;
        int p2 = 0;
        while (p1 < n1 && p2 < n2) {
            if (nums1[p1] > nums2[p2]) {
                p1++;
            }
            p2++;
        }
        return p2 - p1 - 1 < 0 ? 0 : p2 - p1 - 1;
    }
};

int main() {
    vector<int> nums1 = {5,4};
    vector<int> nums2 = {3,2};
    Solution solution;
    cout << solution.maxDistance(nums1, nums2) << endl;
    return 0;
}
