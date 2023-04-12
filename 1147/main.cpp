#include "debug_helper.h"

using namespace std;

class Solution {
public:
    bool is_same(const string& text, int l, int r, int length) {
        while(length--) {
            if (text[l - length] != text[r - length]) {
                return false;
            }
        }
        return true;
    }

    int longestDecomposition(string text) {
        int n = text.length();
        int l = 0;
        int r = n - 1;
        int result = 0;
        while (l < r) {
            int sub_max = (r - l + 1) >> 1;
            int length = 1;
            for (; length <= sub_max; length++) {
                if (is_same(text, l + length - 1, r, length)) {
                    cout << l << "," << r << ":" << length << endl;
                    l += length;
                    r -= length;
                    result += 2;
                    break;
                }
            }
            if (length > sub_max || l == r) {
                result += 1;
                break;
            }
        }
        return result;
    }
};

int main() {
    string in = "ghiabcdefhelloadamhelloabcdefghi";
    in = "aaa";
    Solution solution;
    cout << solution.longestDecomposition(in) << endl;
    return 0;
}
