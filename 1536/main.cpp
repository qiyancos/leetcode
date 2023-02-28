#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zero_count(n, 0);
        for(int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (!grid[i][j]) {
                    zero_count[i] ++;
                } else {
                    break;
                }
            }
        }
        //cout << zero_count << endl;
        int result = 0;
        for (int i = n - 1; i >= 0; i--) {
            int start = n - i - 1;
            for (int j = start; j < n; j++) {
                if (zero_count[j] >= i) {
                    //cout << i << ":" << j << endl;
                    result += (j == start ? 0 : j - start);
                    for (int z = j; z > start; z--) {
                        zero_count[z] = zero_count[z - 1];
                    }
                    start = -1;
                    break;
                }
            }
            if (start != -1) {
                return -1;
            }
            //cout << zero_count << endl;
            //cout << result << endl;
        }
        return result;
    }
};

int main() {
	vector<vector<int>> grid = {{0,0,1},{1,1,0},{1,0,0}};
    Solution solution;
    cout << solution.minSwaps(grid) << endl;
    return 0;
}
