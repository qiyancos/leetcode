#include "debug_helper.h"

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        const int n1 = str1.length();
        const int n2 = str2.length();
        const int nmax = n1 + n2;
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n2; i++) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= n1; i++) {
            dp[i][0] = i;
        }
        for (int i1 = 1; i1 <= n1; i1++) {
            for (int i2 = 1; i2 <= n2; i2++) {
                if (str1[i1 - 1] == str2[i2 - 1]) {
                    dp[i1][i2] = dp[i1 - 1][i2 - 1] + 1;
                } else {
                    dp[i1][i2] = min(dp[i1][i2 - 1] + 1, dp[i1 - 1][i2] + 1);
                }
                cout << i1 << "-" << i2 << ": " << dp[i1][i2] << endl;
            }
        }
        int i1 = n1 -1, i2 = n2 - 1;
        string result;
        while (i1 >= 0 && i2 >= 0) {
            if (str1[i1] == str2[i2]) {
                result += str1[i1];
                i1 --;
                i2 --;
            } else if (dp[i1 + 1][i2 + 1] == dp[i1 + 1][i2] + 1) {
                result += str2[i2];
                i2 --;
            } else if (dp[i1 + 1][i2 + 1] == dp[i1][i2 + 1] + 1) {
                result += str1[i1];
                i1 --;
            }
            cout << i1 << "-" << i2 << ": " << result << endl;
        }
        reverse(result.begin(), result.end());
        if (i1 >= 0) {
            result = str1.substr(0, i1 + 1) + result;
        } else if (i2 >= 0) {
            result = str2.substr(0, i2 + 1) + result;
        }
        return result;
    }
};

int main() {
    string a = "acbbcccaa";
    string b = "bbbcaaaaa";
    Solution solution;
    cout << solution.shortestCommonSupersequence(a,b) << endl;
    return 0;
}
