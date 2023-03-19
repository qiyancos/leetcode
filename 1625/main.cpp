#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int get_gap(char origin, bool to_zero, bool is_five) {
        int gap = origin - '0';
        if (is_five) {
            gap = gap >= 5 ? 5 : 0;
        } else if (!to_zero) {
            gap -= gap & 1 ? 1 : 0;
        }
        return gap;
    }

    string findLexSmallestString(string s, int a, int b) {
        int size = s.length();
        bool to_zero = (a != 5 && (a & 1));
        bool is_five = a == 5;
        int rotate_size = __gcd(size, b);
        string result = s;
        for (int i = 1; i < size; i += 2) {
            string test = s;
            int gap = get_gap(s[i], to_zero, is_five);
            // cout << "---" << gap << "---" << endl;
            for (int j = 1; j < size; j += 2) {
                test[j] = (test[j] - '0' - gap + 10) % 10 + '0';
            }
            if (b & 1) {
                for (int j = 0; j < size; j += 2) {
                    gap = get_gap(s[j], to_zero, is_five);
                    // cout << gap << endl;
                    string in_test = test;
                    for (int k = 0; k < size; k += 2) {
                        in_test[k] = (in_test[k] - '0' - gap + 10) % 10 + '0';
                    }
                    // cout << in_test << endl;
                    for (int r = 0; r < size; r += rotate_size) {
                        string new_str = in_test.substr(size - r, r) + in_test.substr(0, size - r);
                        result = min(new_str, result);
                    }
                }
            } else {
                for (int r = 0; r < size; r += rotate_size) {
                    string new_str = test.substr(size - r, r) + test.substr(0, size - r);
                    result = min(new_str, result);
                }
            }
        }
        return result;
    }
};

int main() {
    string s = "5562438547";
    int a = 1, b = 3;
    Solution solution;
    cout << solution.findLexSmallestString(s,a,b) << endl;
    return 0;
}
