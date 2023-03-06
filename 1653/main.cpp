#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int length = s.length();
        int a_count = s[0] == 'a';
        vector<int> dp(length, 1);
        for (int i = 1; i < length; i++) {
            const char item = s[i];
            if (item == 'a') {
                a_count ++;
                dp[i] = max(dp[i - 1], a_count);
            } else {
                dp[i] = dp[i - 1] + 1;
            }
        }
        return length - dp.back();
    }
};

int main() {
    string input = "bbaaaaabbaaaaaaa";
    Solution solution;
    cout << solution.minimumDeletions(input) << endl;
    return 0;
}
