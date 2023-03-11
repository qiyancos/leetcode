#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0;
        int white_count = 0;
        int min_op = k;
        for (int i = 0; i < blocks.length(); i++) {
            if (count < k) {
                count ++;
                white_count += blocks[i] == 'W';
            } else {
                min_op = min(min_op, white_count);
                white_count += blocks[i] == 'W';
                white_count -= blocks[i - k] == 'W';
            }
        }
        min_op = min(min_op, white_count);
        return min_op;
    }
};

int main() {
    string blocks = "WBBWWBBWBW";
    int k = 7;
    Solution solution;
    cout << solution.minimumRecolors(blocks, k) << endl;
    return 0;
}
