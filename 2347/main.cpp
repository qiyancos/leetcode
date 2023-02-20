#include "debug_helper.h"

using namespace std;

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        bool flush = true;
        for (int i = 1; i < 5; i++) {
            if (suits[i] != suits[i - 1]) {
                flush = false;
                break;
            }
        }
        if (flush) {
            return "Flush";
        }
        vector<int> num_count(14, 0);
        int max_same = 0;
        for (const auto& num : ranks) {
            num_count[num] ++;
            max_same = max(num_count[num], max_same);
            if (max_same ==3 ) {
                return "Three of a Kind";
            }
        }
        if (max_same == 2) {
            return "Pair";
        } else {
            return "High Card";
        }
    }
};

int main() {
    vector<int> ranks = {13,2,3,1,9};
    vector<char> suits = {'a', 'a', 'a', 'a', 'a'}; 
    Solution solution;
    cout << solution.bestHand(ranks, suits) << endl;
    return 0;
}
