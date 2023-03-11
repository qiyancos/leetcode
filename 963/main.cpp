#include "debug_helper.h"

using namespace std;

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
		unordered_set<int> point_set;
        for (const auto point : points) {
            point_set.insert(point[0] * 40000 + point[1]);
        }
        double min_area = 40000 * 40000;
        for (int i = 0; i < points.size() - 1; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < points.size(); j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int xsum = x1 + x2;
                int ysum = y1 + y2;
                for(int k = 0; k < points.size(); k++) {
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    int x4 = xsum - x3;
                    int y4 = ysum - y3;
                    if (k != i && k != j && point_set.find(x4 * 40000 + y4) != point_set.end()) {
                        double cross1 = pow(x1 - x2, 2) + pow(y1 - y2, 2);
                        double cross2 = pow(x3 - x4, 2) + pow(y3 - y4, 2);
                        if (cross1 == cross2) {
                            // cout << "(" << x1 << "," << y1 << ") ";
                            // cout << "(" << x2 << "," << y2 << ") ";
                            // cout << "(" << x3 << "," << y3 << ") ";
                            // cout << "(" << x4 << "," << y4 << ") " << endl;
                            double area = sqrt(pow(double(x1) - x3, 2) + pow(double(y1) - y3, 2)) *
                                    sqrt(pow(double(x1) - x4, 2) + pow(double(y1) - y4, 2));
                            // cout << area << endl;
                            min_area = min(area, min_area);
                        }
                    }
                }
            }
        }
        return min_area == 40000 * 40000 ? 0 : min_area;
    }
};

int main() {
    vector<vector<int>> points = {{0,1},{2,1},{1,1},{1,0},{2,0}};
    Solution solution;
    cout << solution.minAreaFreeRect(points) << endl;
    return 0;
}
