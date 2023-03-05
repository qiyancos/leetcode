#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int length = floor.length();
        if (numCarpets * carpetLen >= length) {
            return 0; 
        }
        vector<int> cover_count(length, 0);
        vector<vector<int>> dp(numCarpets + 1, vector<int>(length, 0));
        int total = 0;
        int carpet_white = 0;
        for (int i = 0; i < length; i++) {
            if (floor[i] == '1') {
                carpet_white += (i < carpetLen || floor[i] != floor[i - carpetLen]);
                total ++;
            } else if (floor[i] == '0' && i >= carpetLen && floor[i] != floor[i - carpetLen]) {
                carpet_white --;
            }
            cover_count[i] = carpet_white;
            dp[1][i] = max(carpet_white, i == 0 ? 0 : dp[1][i - 1]);
        }
        cout << cover_count << endl;
        for (int count = 2; count <= numCarpets; count++) {
            int left = carpetLen * count - 1;
            for (int start = left; start < length; start++) {
                dp[count][start] = max(dp[count - 1][start - carpetLen] + cover_count[start], dp[count][start - 1]);
            }
            cout << dp[count] << endl;
        }
        return total - dp[numCarpets][length - 1];
    }
};

int main() {
    string floor = "110000";
    int carpetlen = 1;
    int numCarpets = 1;
    Solution solution;
    cout << solution.minimumWhiteTiles(floor, numCarpets, carpetlen) << endl;
    return 0;
}
