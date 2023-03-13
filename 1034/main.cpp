#include "debug_helper.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int max_x = grid.size();
        int max_y = grid[0].size();
        int base = grid[row][col];
        
        vector<vector<int>> color_list(1, {row,col});
        vector<vector<int>> border;
        set<int> checked;
        
        checked.insert((row << 6) + col);
        vector<vector<int>> offset_list = {{0,-1},{0,1},{1,0},{-1,0}};
        while (!color_list.empty()) {
            // 首先判断border
            vector<vector<int>> new_color_list;
            for (const auto& point : color_list) {
                bool is_border = false;
                for (const auto& offset : offset_list) {
                    int x = point[0] + offset[0];
                    int y = point[1] + offset[1];
                    if (x < 0 || y < 0 || x >= max_x || y >= max_y || grid[x][y] != base) {
                        is_border = true;
                        continue;
                    }
                    int coord = (x << 6) + y;
                    if (checked.find(coord) != checked.end()) {
                        continue;
                    }
                    new_color_list.push_back({x,y});
                }
                if (is_border) {
                    border.push_back(point);
                }
                int coord = (point[0] << 6) + point[1];
                checked.insert(coord);
            }
            color_list = new_color_list;
        }
        for (const auto& point : border) {
            grid[point[0]][point[1]] = color;
        }
        return grid;
    }
};

int main() {
    vector<vector<int>> grid = {{1,1,1},{1,1,2},{1,2,2}};
    int row = 0;
    int col = 0;
    int color = 3;
    Solution solution;
    cout << solution.colorBorder(grid, row, col, color) << endl;
    return 0;
}
