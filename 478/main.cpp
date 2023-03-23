#include "debug_helper.h"

using namespace std;

class Solution {
public:
    double left;
    double down;
    double dr;
    double ra;
    
    Solution(double radius, double x_center, double y_center) {
        dr = radius * 2;
        left = x_center - radius;
        down = y_center - radius;
        ra = radius;
    }
    
    vector<double> randPoint() {
        bool inside = false;
        double coord_x;
        double coord_y;
        while (!inside) {
            coord_x = double(rand() % int(1e9)) / 1e9 * dr;
            coord_y = double(rand() % int(1e9)) / 1e9 * dr;
            inside = sqrt(pow(coord_x - ra, 2) + pow(coord_y - ra, 2)) <= ra;
        }
        return {coord_x + left, coord_y + down};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

int main() {
    Solution solution(1.0, 0.0, 0.0);
    int count = 1000;
    while (count--) {
        cout << solution.randPoint() << endl;
    }
    return 0;
}
