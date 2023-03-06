#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(verticalCuts.begin(), verticalCuts.end());
        int max_h = 0;
        for (int i = 1; i < horizontalCuts.size(); i++) {
            max_h = max(max_h, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        int max_w = 0;
        for (int i = 1; i < verticalCuts.size(); i++) {
            max_w = max(max_w, verticalCuts[i] - verticalCuts[i - 1]);
        }
        return (long long)max_h * max_w % int(1e9 + 7);
    }
};

int main() {
	int h = 5;
    int w = 4;
    vector<int> hCuts = {1,3};
    vector<int> vCuts = {1};
    Solution solution;
    cout << solution.maxArea(h, w, hCuts, vCuts) << endl;
    return 0;
}
