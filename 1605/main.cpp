#include "debug_helper.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int row = rowSum.size();
        int col = colSum.size();
        vector<int> row_sum_now(row, 0);
        vector<int> col_sum_now(col, 0);
        vector<vector<int>> grid(row, vector<int>(col, 0));
        for (int i = col - 1; i >= 0; i--) {
            grid[row - 1][i] = min(min(colSum[i], rowSum[row - 1]),
                    rowSum[row - 1] - row_sum_now[row - 1]);
            row_sum_now[row - 1] += grid[row - 1][i];
            col_sum_now[i] += grid[row - 1][i];
        }
        cout << grid << endl;
        for (int i = col - 1; i >= 0; i--) {
            for (int j = row - 2; j >= 0; j--) {
                grid[j][i] = min(min(rowSum[j], colSum[i] - col_sum_now[i]),
                        rowSum[j] - row_sum_now[j]);
                cout << grid << endl;
                col_sum_now[i] += grid[j][i];
                row_sum_now[j] += grid[j][i];
            }
        }
        return grid;
    }
};

int main() {
    vector<int> row_sum = {0};
    vector<int> col_sum = {0};
    Solution solution;
    cout << solution.restoreMatrix(row_sum, col_sum) << endl;
    return 0;
}
