#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int commonFactors(int a, int b) {
        int rem = a % b;
        while (rem != 0) {
            a = b;
            b = rem;
            rem = a % b;
        }
        int count = 1;
        for (int i = 1; i < b; i++) {
            count += (a % i == 0 && b % i == 0);
        }
        return count;
    }
};

int main() {
    int a = 25;
    int b = 30;
    Solution solution;
    cout << solution.commonFactors(a,b) << endl;
    return 0;
}
