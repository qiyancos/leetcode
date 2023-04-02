#include "debug_helper.h"

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        vector<int> acc(n, 1);
        vector<bool> nums(n, true);
        for (int i = 1; i < n; i++) {
            acc[i] = i * acc[i - 1];
        }
        while(n) {
            int index = (k - 1) / acc[n - 1] + 1;
            int count_down = index;
            int i = 0;
            while (count_down) {
                if (nums[i]) {
                    count_down--;   
                }
                i++;
            }
            result += to_string(i);
            k -= (index - 1) * acc[n - 1];
            nums[i - 1] = false;
            n--;
            // cout << n << ": " << k << "," << index << "," << nums << "," << result << endl;
        }
        return result;
    }
};

int main() {
    int n = 4, k = 9;
    Solution solution;
    cout << solution.getPermutation(n, k) << endl;
    return 0;
}
