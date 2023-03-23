#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int expectNumber(vector<int>& scores) {
        set<int> score_set;
        for (const auto score : scores) {
            score_set.insert(score);
        }
        return score_set.size();
    }
};

int main() {
    vector<int> scores = {1,2,3};
    Solution solution;
    cout << solution.expectNumber(scores) << endl;
    return 0;
}
