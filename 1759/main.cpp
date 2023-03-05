#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int countHomogenous(string s) {
        int length = s.length();
        if (length == 1) {
            return 1;
        }
		int border = 1e9 + 7;
        long long total = 0;
        long long continue_count = 1;
        char last_item = s[0];
        for (int i = 1; i < length; i++) {
            if (s[i] != last_item) {
                total += (continue_count * (continue_count + 1)) >> 1;
                if (total > border) total %= border;
                last_item = s[i];
                continue_count = 1;
            } else {
                continue_count ++;
            }
        }
        total += (continue_count * (continue_count + 1)) >> 1;
        return total % border;
    }
};

int main() {
	string input = "abbcccaa";
    Solution solution;
    cout << solution.countHomogenous(input) << endl;
    return 0;
}
