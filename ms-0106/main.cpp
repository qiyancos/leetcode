#include "debug_helper.h"

using namespace std;

class Solution {
public:
    string compressString(string S) {
        string out;
        int count = 0;
        char now = '0';
        for (const auto& alpha : S) {
            if (alpha != now) {
                if (now != '0') {
                    out = out + to_string(count) + alpha;
                } else {
                    out += alpha;
                }
                now = alpha;
                count = 0;
            }
            count ++;
        }
        out += to_string(count);
        return out.length() < S.length() ? out : S;
    }
};

int main() {
    string in = "aabcccccaaa";
    Solution solution;
    cout << solution.compressString(in) << endl;
    return 0;
}
