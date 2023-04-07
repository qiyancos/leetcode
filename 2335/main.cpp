#include "debug_helper.h"

using namespace std;

ass Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        if (amount[2] > amount[1] + amount[0]) {
            return amount[2];
        }
        return (accumulate(amount.begin(), amount.end(), 0) + 1) / 2;
    }
};

int main() {
    vector<int> in = {5,4,4};
    Solution solution;
    cout << solution.fillCups(in) << endl;
    return 0;
}
