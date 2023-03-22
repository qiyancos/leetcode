#include "debug_helper.h"

using namespace std;

class Solution {
public:
    bool check(string s, unordered_map<string, bool>& record) {
        if (s.length() == 1 or record.find(s) != record.end()) {
            return true;
        }
        int size = s.length();
        for (int i = 0; i < (size >> 1); i++) {
            if (s[i] != s[size - i - 1]) {
                return false;
            }
        }
        record[s] = true;
        return true;
    }
    
    int minCut(string s) {
        unordered_map<string, bool> record;
        if (check(s, record)) {
            return 0;
        }
        int size = s.length();
        vector<int> dp(size + 1, 2000);
        dp[0] = -1;
        for (int i = 1; i <= size; i++) {
            if (check(s.substr(0,i), record)) {
                dp[i] = 0;
            } else {
                int min_cut = 2000;
                for (int count = i; count > 0; count--) {
                    string sub = s.substr(i - count, count);
                    if (check(sub, record)) {
                        min_cut = min(min_cut, dp[i - count] + 1);
                    }
                }
                dp[i] = min_cut;
            }
            // cout << dp << endl;
        }
        return dp[size];
    }
};

int main() {
    string s = "aabbbaakccddcc";
    Solution solution;
    cout << solution.minCut(s) << endl;
    return 0;
}
