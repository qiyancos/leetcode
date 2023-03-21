#include "debug_helper.h"

using namespace std;

class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> count(10, 0);
        for (const auto n : num) {
            count[n - '0'] ++;
        }
        string left;
        int max_left = -1;
        for (int i = 9; i >= 0; i--) {
            if (count[i] & 1 && max_left == -1) {
                max_left = i;
            }
            if (left.length() or i != 0) {
                left.append(count[i] >> 1, '0' + i);
            }
        }
        string result = left;
        if (max_left != -1) {
            result += to_string(max_left);
        }
        for (int i = left.length() - 1; i >= 0; i--) {
            result.append(1, left[i]);
        }
        return result.length() ? result : "0";
    }
};

int main() {
    string num = "6006";
    Solution solution;
    cout << solution.largestPalindromic(num) << endl;
    return 0;
}
