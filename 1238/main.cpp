#include "debug_helper.h"

using namespace std;

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> result(1<<n);
        for (int i = 0; i < (1 << n); i ++) {
            result[i] = i ^ (i >> 1) ^ start;
        }
        return result;
    }
};

int main() {
    int n = 3;
    int start = 2;
    Solution solution;
    cout << solution.circularPermutation(n, start) << endl;
    return 0;
}
