#include "debug_helper.h"

using namespace std;


// This is the custom function interface.
// You should not implement it, or speculate about its implementation
class CustomFunction {
public:
    // Returns f(x, y) for any given positive integers x and y.
    // Note that f(x, y) is increasing with respect to both x and y.
    // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
    int f(int x, int y) {
        return x * y;
    }
};


class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> result;
        int last_y = 1000;
        for (int x = 1; x <= 1000; x++) {
            int left_y = 1;
            int right_y = last_y;
            // cout << x << ": " << left_y << "-" << right_y << endl;
            while (left_y < right_y) {
                int left_y_z = customfunction.f(x, left_y);
                if (z <= left_y_z) {
                    if (z == left_y_z) {
                        result.push_back(vector<int>({x, left_y}));
                    } else if (left_y == 1) {
                        x = 1001;
                    }
                    break;
                }
                int mid_y = (left_y + right_y) >> 1;
                // cout << left_y << '-' << mid_y << '-' << right_y << endl;
                int mid_y_z = customfunction.f(x, mid_y);
                if (z == mid_y_z) {
                    result.push_back(vector<int>({x, mid_y}));
                    last_y = mid_y;
                    break;
                }
                int right_y_z = customfunction.f(x, right_y);
                if (z >= right_y_z) {
                    if (z == right_y_z) {
                        result.push_back(vector<int>({x, right_y}));
                        last_y = right_y;
                    }
                    break;
                } else if (z < mid_y_z) {
                    right_y = mid_y - 1;
                    // cout << "ToLeft: " << left_y << '-' << right_y << endl;
                } else if (z > mid_y_z) {
                    left_y = mid_y + 1;
                    // cout << "ToRight: " << left_y << "-" << right_y << endl;
                }
            }
        }
        return result;
    }
};

int main() {
    int z = 100;
    CustomFunction func;
    Solution solution;
    cout << solution.findSolution(func, z) << endl;
    return 0;
}
