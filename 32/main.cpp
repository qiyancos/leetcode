#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int max_count = 0;
        vector<int> dp(s.length(), 0);
        for (int i = 1 ; i < s.length(); i++) {
            if (s[i] == ')') {
                int last_not_match = (dp[i - 1] == 0 ? i - 1 : i - 1 - dp[i - 1]);
                if (last_not_match >= 0 && s[last_not_match] != s[i]) {
                    dp[i] = dp[i - 1] + 2;
                    last_not_match--;
                    if (last_not_match >= 0 && dp[last_not_match] != 0) {
                        dp[i] += dp[last_not_match];
                    }
                } else {
                    dp[i] = 0;
                }
            } else {
                dp[i] = 0;
            }
            max_count = max(max_count, dp[i]);
        }
        return max_count;
    }
};

int main() {
    string input = ")((()())()((())()()";
    input = "())";
    Solution solution;
    cout << solution.longestValidParentheses(input) << endl;
    return 0;
}
