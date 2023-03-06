#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        for (int i = 0; i < dist.size(); i++) {
            dist[i] = (dist[i] + speed[i] - 1) / speed[i];
        }
        sort(dist.begin(), dist.end());
        // cout << dist << endl;
        int min = 0;
        int next = 0;
        int result = 0;
        for (int next = 0; next < dist.size(); next++, min++, result++) {
            if (dist[next] - min <= 0) {
                return result;
            }
        }
        return result;
    }
};

int main() {
	vector<int> dist = {1,5,3,4};
	vector<int> speed = {1,1,1,2};
    Solution solution;
    cout << solution.eliminateMaximum(dist, speed) << endl;
    return 0;
}
