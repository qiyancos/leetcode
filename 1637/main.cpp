#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
                [](const vector<int>& a, const vector<int>& b)->bool {return a[0] < b[0];});
        int max_gap = 0;
        for (int i = 1; i < points.size(); i++) {
            max_gap = max(max_gap, points[i][0] - points[i - 1][0]);
        }
        return max_gap;
    }
};

int main() {
    vector<vector<int>> ps = {{8,7},{9,9},{7,4},{9,7}};
    Solution solution;
    cout << solution.maxWidthOfVerticalArea(ps) << endl;
    return 0;
}
