#include "debug_helper.h"

using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto compare = [](const pair<int, int>& a, const pair<int, int>& b)->bool{
            if (a.second == b.second) return a.first > b.first;
            double avg1 = (a.first + 0.0) / a.second;
            double avg1_add = (a.first + 1.0) / (a.second + 1.0);
            double avg2 = (b.first + 0.0) / b.second;
            double avg2_add = (b.first + 1.0) / (b.second + 1.0);
            return avg1_add - avg1 < avg2_add - avg2;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> class_list(compare);
        double total = 0;
        for (const auto& class_info : classes) {
            // 跳过100%班级
            if (class_info[0] != class_info[1]) {
                class_list.push(pair<int, int>(class_info[0], class_info[1]));
            } else {
                total += 1;
            }
        }
        if (class_list.empty()) {
            return total / classes.size();
        }
        cout << class_list << endl;
        while (extraStudents--) {
            auto class_now = class_list.top();
            class_list.pop();
            class_now.first += 1;
            class_now.second += 1;
            class_list.push(class_now);
            cout << class_list << endl;
        }
        while (!class_list.empty()) {
            auto class_now = class_list.top();
            class_list.pop();
            total += double(class_now.first) / class_now.second;
        }
        return total / classes.size();
    }
};

int main() {
	// vector<vector<int>> input  = {{2,4},{3,9},{4,5},{2,10}};
	// vector<vector<int>> input  = {{1,2}, {3,5}, {2,2}};
	vector<vector<int>> input  = {{583,868},{783,822},{65,262},{121,508},{461,780},{484,668}};
    int extra = 8;
    Solution solution;
    cout << solution.maxAverageRatio(input, extra) << endl;
    return 0;
}
