#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int countSubstrings(string s, string t) {
        int s_size = s.length();
        int t_size = t.length();
        vector<vector<int>> dpl(s_size + 1, vector<int>(t_size + 1, 0));
        vector<vector<int>> dpr(s_size + 1, vector<int>(t_size + 1, 0));
        for (int i = 0; i < s_size; i++) {
            for (int j = 0; j < t_size; j++) {
                dpl[i + 1][j + 1] = s[i] == t[j] ? dpl[i][j] + 1 : 0;
            }
        }
        for (int i = s_size - 1; i >= 0; i--) {
            for (int j = t_size - 1; j >= 0; j--) {
                dpr[i][j] = s[i] == t[j] ? dpr[i + 1][j + 1] + 1 : 0;
            }
        }
        int result = 0;
        for (int i = 0; i < s_size; i++) {
            for (int j = 0; j < t_size; j++) {
                if (s[i] != t[j]) {
                    result += (dpl[i][j] + 1) * (dpr[i + 1][j + 1] + 1);
                }
            }
        }
        return result;
    }
};

int main() {    
    string a = "aba";
    string b = "baba";
    Solution solution;
    cout << solution.countSubstrings(a, b) << endl;
    return 0;
}
