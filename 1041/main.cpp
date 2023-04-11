#include "debug_helper.h"

using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        const vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int x = 0, y = 0;
        int dir_i = 0;
        for (const auto step : instructions) {
            if (step == 'G') {
                x += dir[dir_i][0];
                y += dir[dir_i][1];
            } else if (step == 'L') {
                dir_i -= 1;
                if (dir_i == -1) {
                    dir_i = 3;
                }
            } else {
                dir_i += 1;
                if (dir_i == 4) {
                    dir_i = 0;
                }
            }
        }
        cout << dir_i << "," << x << "," << y << endl;
        return dir_i != 0 || (x == 0 && y == 0);
    }
};

int main() {
    string in = "GLRLLGLL";
    Solution solution;
    cout << solution.isRobotBounded(in) << endl;
    return 0;
}
