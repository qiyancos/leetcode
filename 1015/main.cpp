#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int last_left = 1;
        int total_left = 0;
        int i = 1;
        vector<bool> exist(k, false);
        while (i < k + 1) {
            // cout << i << ": (" << last_left << "," << total_left << ")" << endl;
            int left = last_left % k;
            total_left = (total_left + left) % k;
            if (total_left == 0) {
                return i;
            } else {
                last_left = left * 10;
                i ++;
                if (exist[total_left]) {
                    return -1;
                } else {
                    exist[total_left] = true;
                }
            }
        }
        return -1;
    }
};

int main() {
    int k = 3;
    Solution solution;
    cout << solution.smallestRepunitDivByK(k) << endl;
    return 0;
}
