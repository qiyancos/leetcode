#include "debug_helper.h"

using namespace std;

class Solution {
public: 
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        int res_size = restrictions.size();
        if (res_size == 0) {
            return n - 1;
        }
        restrictions.push_back({n, n -1});
        sort(restrictions.begin(), restrictions.end(),
                [](const vector<int>& a, const vector<int>& b)->bool{return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];});

        for (int i = res_size - 1; i>=0; i--) {
            restrictions[i][1] = min(restrictions[i][1],
                    restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0]);
        }

        // cout << restrictions << endl;
        int max_h = 0;
        int max_decay = 0;
        int last_index = 1; 
        for (int i = 0; i < res_size + 1; i++) {
            vector<int>& res = restrictions[i];
            int new_decay = res[0] - 1 -res[1];
            if (new_decay > max_decay) {
                int gap = res[0] - last_index - 1;
                int last_res = last_index - 1 - max_decay;
                int new_h = (res[1] + last_res + gap + 1) >> 1;
                max_h = max(max_h, new_h);
                max_decay = new_decay;
                last_index = res[0];
            } else if (res[0] == n) {
                int new_h = n - last_index + last_index - 1 - max_decay;
                // cout << last_index << '-' << res[0] << ": " << new_h << endl;
                max_h = max(max_h, new_h);
                i ++;
            }
        }
        return max_h;                                       
    }
};

int main() {
    int n = 100;
    // vector<vector<int>> b= {{5,3},{2,5},{7,4},{10,3}};
    // vector<vector<int>> b= {{7,4},{8,1},{9,0}};
    // vector<vector<int>> b= {{6,2},{5,1},{2,4},{3,0},{9,5},{7,0},{4,2},{10,3},{8,0}};
    vector<vector<int>> b= {{68,36},{25,30},{81,2},{7,26},{63,35},{83,33},{36,22},{21,50},{13,27},{57,50},{100,35},{92,9},{89,27},{29,39},{9,3},{37,22},{98,5},{18,38},{87,30},{67,43},{71,15},{45,20},{97,21},{46,15},{24,17},{17,10},{90,12},{41,0},{79,3},{77,42},{61,29},{69,21},{53,8},{64,45},{6,2},{51,21},{40,5},{93,30},{99,12},{32,36},{5,36},{26,34},{2,35},{20,24},{66,45},{12,15},{96,10},{52,19},{19,9},{14,47},{74,25},{56,39},{82,27},{86,42},{33,47},{88,38},{70,48},{91,11},{73,33},{31,8},{85,21},{8,50},{65,0},{78,36},{11,3},{27,0},{16,4},{49,30},{10,42},{76,32},{35,0},{60,45},{39,39},{43,25},{15,39},{84,15},{75,45},{54,9},{80,7},{58,4},{55,43},{30,8},{38,48},{22,40},{47,24},{62,12},{59,33},{48,12},{50,9},{28,30},{34,19},{4,19},{95,26},{72,12},{3,46},{94,25},{44,32},{42,48},{23,48}};
    Solution solution;
    cout << solution.maxBuilding(n, b) << endl;
    return 0;
}
