#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int f(int n, int m) {
        if (n == 1) {
            return 0;
        }
        int x = (m + f(n - 1, m)) % n;
        cout << n << ": " << x << endl;
        return x;
    }
    
    int lastRemaining(int n, int m) {
        return f(n, m);
    }
};

int main() {
	int n = 5;
    int m = 3;
    Solution solution;
    cout << solution.lastRemaining(n, m) << endl;
    return 0;
}
