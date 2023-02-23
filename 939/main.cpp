#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
		set<unsigned int> point_set;
        for (const auto point : points) {
            point_set.insert((point[0] << 16) | point[1]);
        }
        // cout << point_set << endl;
        int min_size = 1600000001;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                if (points[i][0] != points[j][0] && points[i][1] != points[j][1]) {
                    // cout << points[i] << ":" << points[j] << endl;
                    int new_size = (abs(points[i][0] - points[j][0]) *
                            abs(points[i][1] - points[j][1]));
                    if (new_size < min_size) {
                        unsigned int point_a = (points[i][0] << 16) | points[j][1];
                        unsigned int point_b = (points[j][0] << 16) | points[i][1];
                        if (point_set.find(point_a) != point_set.end() &&
                                point_set.find(point_b) != point_set.end()) {
                            min_size = new_size;
                        }
                    }
                    // cout << min_size << endl;
                }
            }
        }
        return min_size <= 1600000000 ? min_size : 0;
    }
};

int main() {
	vector<vector<int>> points = {{1,1},{1,3},{3,1},{3,3},{2,2}};
    Solution solution;
    cout << solution.minAreaRect(points) << endl;
    return 0;
}
