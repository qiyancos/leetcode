#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int point_count = points.size();
        vector<vector<unsigned int>> distance(point_count, vector<unsigned int>(point_count, 1e9));
        for (int i = 0; i < point_count; i++) {
            for (int j = i + 1; j < point_count; j++) {
                distance[i][j] = distance[j][i] = (abs(points[i][0] - points[j][0]) +
                        abs(points[i][1] - points[j][1]));
            }
        }
        int min_path = 0;
        vector<bool> contained(point_count, false);
        vector<unsigned int> min_dist_uncontained = distance[0];
        contained[0] = true;
        int cal_times = 0;
        while(cal_times++ < point_count - 1) {
            int short_path = 1e9;
            int new_point_index = 0;
            for (int i = 0; i < point_count; i ++) {
                if (!contained[i] && min_dist_uncontained[i] < short_path) {
                    short_path = min_dist_uncontained[i];
                    new_point_index = i;
                }
            }
            contained[new_point_index] = true;
            min_path += short_path;
            for(int i = 0; i < point_count; i++) {
                if (!contained[i]) {
                    min_dist_uncontained[i] = min(min_dist_uncontained[i], distance[new_point_index][i]);
                }
            }
            /* cout << "Add Point" << new_point_index << "-(" <<
                    points[new_point_index][0] << ", " <<
                    points[new_point_index][1] << ")" << endl;
            cout << contained << endl;
            cout << min_path << endl; */
        }
        return min_path;
    }
};

int main() {
    setPrintBeauty(false);
    vector<vector<int>> input;
    input.push_back(vector<int>({0,0}));
    input.push_back(vector<int>({2,2}));
    input.push_back(vector<int>({5,2}));
    input.push_back(vector<int>({7,0}));
    input.push_back(vector<int>({3,10}));
    Solution solution;
    cout << solution.minCostConnectPoints(input) << endl;
    return 0;
}
