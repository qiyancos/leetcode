#include "debug_helper.h"

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int size = intervals.size();
        vector<vector<int>> start_list;
        for (int i = 0; i < size; i ++) {
            start_list.push_back({intervals[i][0], i});
        }
        sort(start_list.begin(), start_list.end(),
                [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];});
        int max_start = start_list.back()[0];
        cout << start_list << endl;
        vector<int> result(size, 0);
        unordered_map<int, int> checked;
        for (int i = 0; i < size; i++) {
            int end = intervals[i][1];
            cout << end << endl;
            if (end > max_start) {
                result[i] = -1;
            } else if (checked.find(end) != checked.end()) {
                result[i] = checked[end];
            } else {
                int left = 0;
                int right = size;
                int mid = 0;
                while(left < right) {
                    mid = (left + right) >> 1;
                    cout << left << "-" << mid << "(" << start_list[mid] << ")" << "-" << right << endl;
                    if (start_list[mid][0] < end) {
                        if (start_list[mid + 1][0] >= end) {
                            mid ++;
                            break;
                        }
                        left = mid + 1;
                    } else if (start_list[mid][0] == end) {
                        break;
                    } else {
                        right = mid;
                    }
                }
                result[i] = start_list[mid][1];
                checked[end] = result[i];
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> input = {{1,12},{2,9},{3,10},{13,14},{15,16},{16,17}};
    Solution solution;
    cout << solution.findRightInterval(input) << endl;
    return 0;
}
