#include "debug_helper.h"

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        if (groupSize == 1) {
            return true;
        }
        sort(hand.begin(), hand.end());
        // cout << hand << endl;
        int total_count = 0;
        int last_start = 0;
        while (true) {
            int next = -1;
            int count = 0;
            for (int i = last_start; i < hand.size(); i++) {
                if (hand[i] == -1) {
                    continue;
                } else if (next == -1) {
                    // cout << hand[i] << endl;
                    next = hand[i] + 1;
                    hand[i] = -1;
                    count = 1;
                    last_start = i + 1;
                } else if (hand[i] == next) {
                    // cout << hand[i] << endl;
                    next ++;
                    hand[i] = -1;
                    count ++;
                    if (count == groupSize) {
                        total_count += count;
                        break;
                    }
                } else if (hand[i] > next){
                    return false;
                }
            }
            if (count > 0 && count < groupSize) {
                return false;
            }
            if (total_count == hand.size()) {
                return true;
            }
        }
    }
};

int main() {
    vector<int> hand = {1,1,2,2,3,3};
    int groupsize = 2;
    Solution solution;
    cout << solution.isNStraightHand(hand, groupsize) << endl;
    return 0;
}
