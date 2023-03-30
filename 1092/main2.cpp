#include "debug_helper.h"

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        if (n1 < n2) {
            string temp = str1;
            str1 = str2;
            str2 = temp;
            int nt = n2;
            n2 = n1;
            n1 = nt;
        }
        int max = 0;
        int start = 0;
        for (int li = n1 - 1; li >= 0; li--) {
            int pl = li;
            int ps = n2 - 1;
            bool match = true;
            while (ps >= 0 && pl >= 0) {
                if (str1[pl] == str2[ps]) {
                    pl --;
                    ps --;
                } else {
                    match = false;
                    break;
                }
            }
            if (match) {
                int same_count = li + 1;
                // cout << "Left: " << li << ":" << same_count << endl;
                if (same_count >= n2) {
                    return str1;
                } else if (same_count > max) {
                    max = same_count;
                    start = li;
                }
            }
        }
        for (int li = n1 - n2 + 1; li <= n1 - 1 - max; li++) {
            int pl = li;
            int ps = 0;
            bool match = true;
            while(ps < n2 && pl < n1) {
                if (str1[pl] == str2[ps]) {
                    pl ++;
                    ps ++;
                } else {
                    match = false;
                    break;
                }
            }
            if (match) {
                int same_count = n1 - li;
                // cout << "Right: " << li << ":" << same_count << endl;
                if (same_count > max) {
                    max = same_count;
                    start = -li;
                }
            }
        }
        if (max == 0) {
            return str1 + str2;
        } else if (start > 0) {
            return str2.substr(0, n2 - max) + str1;
        } else {
            return str1 + str2.substr(max, n2 - max);
        }
    }
};

int main() {
    string a = "abacd";
    string b = "bac";
    Solution solution;
    cout << solution.shortestCommonSupersequence(a,b) << endl;
    return 0;
}
