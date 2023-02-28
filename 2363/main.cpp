#include "debug_helper.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<int> value_sum(1001, 0);
        for (const auto item : items1) {
            value_sum[item[0]] += item[1];
        }
        for (const auto item : items2) {
            value_sum[item[0]] += item[1];
        }
        vector<vector<int>> result;
        for (int i = 1; i <= 1000; i++) {
            if (value_sum[i]) {
                result.push_back({i, value_sum[i]});
            }
        }
        return result;
    }
};

int main() {
	vector<vector<int>> items1 = {{1,1},{4,5},{3,8}};
	vector<vector<int>> items2 = {{3,1},{1,5}};
    Solution solution;
    cout << solution.mergeSimilarItems(items1, items2) << endl;
    return 0;
}
