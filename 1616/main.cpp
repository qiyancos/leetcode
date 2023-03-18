#include "debug_helper.h"

using namespace std;

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        int size = a.length();
        if (size == 1) {
            return true;
        }
        int mid = (size + 1) >> 1;
        int a_self = 0, b_self = 0, a_b = mid - 1, b_a = mid - 1;
        bool a_self_over = false, b_self_over = false, a_b_over = false, b_a_over = false;
        for (int i = 0; i < mid; i++) {
            int right = mid - i - 1;
            if (!a_self_over && a[right] != a[size - right - 1]) {
                a_self = right + 1;
                a_self_over = true;
            }
            if (!b_self_over && b[right] != b[size - right - 1]) {
                b_self = right + 1;
                b_self_over = true;
            }
            if (!a_b_over && a[i] != b[size - i - 1]) {
                a_b = i - 1;
                a_b_over = true;
            }
            if (!b_a_over && b[i] != a[size - i - 1]) {
                b_a = i - 1;
                b_a_over = true;
            }
            cout << i << ": " << a_self << ":" << b_self << ", " << a_b << ":" << b_a << endl;
            if (a_self_over && b_self_over && a_b_over && b_a_over) {
                break;
            }
        }
        return a_self - 1 <= a_b || b_self - 1 <= b_a || a_self - 1 <= b_a || b_self - 1 <= a_b;
    }
};

int main() {
    string a = "pvhmupgqeltozftlmfjjde", b = "yjgpzbezspnnpszebzmhvp";
    Solution solution;
    cout << solution.checkPalindromeFormation(a,b) << endl;
    return 0;
}
