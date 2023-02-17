#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        vector<vector<int>> right(height, vector<int>(width, 0));
        vector<vector<int>> down(height, vector<int>(width, 0));
        right[0][0] = down[0][0] = grid[0][0];
        for (int i = 1; i < height; i++) {
            right[i][0] = grid[i][0];
            down[i][0] = grid[i][0] ? down[i - 1][0] + 1 : 0;
        }
        for (int j = 1; j < width; j++) {
            down[0][j] = grid[0][j];
            right[0][j] = grid[0][j] ? right[0][j - 1] + 1 : 0;
        }
        for (int i = 1; i < height; i++) {
            for (int j = 1; j < width; j++) {
                if (grid[i][j]) {
                    right[i][j] = right[i][j - 1] + 1;
                    down[i][j] = down[i - 1][j] + 1;
                }
            }
        }
        cout << right << endl;
        cout << down << endl;
        int max_grid = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int max_length = min(right[i][j], down[i][j]);
                if (max_length == 0) {
                    continue;
                } else if (max_length == 1) {
                    max_grid = max_grid == 0 ? 1 : max_grid;
                } else if (max_length > max_grid) {
                    for (int length = max_length; length > max_grid; length--) {
                        int i_new = i - length + 1;
                        int j_new = j - length + 1;
                        if (down[i][j_new] >= length &&
                                right[i_new][j] >= length &&
                                (down[i][j_new] - down[i_new][j_new] == length - 1) &&
                                (right[i_new][j] - right[i_new][j_new] == length - 1)) {
                            max_grid = length;
                            break;
                        }
                    }
                }
            }
        }
        return max_grid * max_grid;
    }
};

int main() {
    vector<vector<int>> input= {{0,1,1,1,1,0},{1,1,0,1,1,0},{1,1,0,1,0,1},{1,1,0,1,1,1},{1,1,0,1,1,1},{1,1,1,1,1,1},{1,0,1,1,1,1},{0,0,1,1,1,1},{1,1,1,1,1,1}};
    // vector<vector<int>> input= {{0,1},{1,1}};
    // vector<vector<int>> input= {{1,1,1},{1,0,1},{1,1,1}};
    // vector<vector<int>> input= {{0,1,0,1,1},{1,1,1,1,1},{1,1,0,1,1},{1,1,1,1,0},{0,1,1,1,1},{1,1,1,0,1},{0,1,1,1,1},{1,1,1,0,1}};
    // vector<vector<int>> input= {{0,1,0},{0,1,1},{1,1,1}};
    // vector<vector<int>> input= {{1,1,1,0},{1,0,1,1},{1,1,0,0},{1,1,1,1},{0,1,0,1}};
    // vector<vector<int>> input= {{1,1,1,0,1,0,1},{1,1,0,1,1,1,1},{1,1,1,1,1,1,0},{0,1,1,1,1,0,0},{0,1,0,1,1,1,1},{1,1,1,1,1,1,1},{0,1,1,1,1,1,1}};
    // vector<vector<int>> input= {{1,1,1,1,1,1,1,1},{0,1,0,1,1,1,1,0},{1,1,0,1,0,1,1,1},{1,1,1,1,1,1,0,0}};
    Solution solution;
    cout << solution.largest1BorderedSquare(input) << endl;
    return 0;
}
