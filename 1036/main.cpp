#include "debug_helper.h"

using namespace std;

class Solution {
public:
    bool check_point(const vector<int>& point, unordered_set<long long>& reached,
            list<vector<int>>& new_point_list, const long long end_coord) {
        if (point[0] < 0 || point[0] >= 1e6 || point[1] < 0 || point[1] >= 1e6) {
            return false;
        }
        long long point_coord = point[0] * 1e6 + point[1];
        if (point_coord == end_coord) return true;
        if (reached.find(point_coord) == reached.end()) {
            new_point_list.push_back(point);
            reached.insert(point_coord);
        }
        return false;
    }

    int check_start(const vector<int>& start, const vector<int>& end,
            const unordered_set<long long>& blocked_set) {
        unordered_set<long long> reached = blocked_set;
        reached.insert(start[0] * 1e6 + start[1]);
        long long end_coord = end[0] * 1e6 + end[1];
        list<vector<int>> point_list;
        point_list.push_back(start);
        while (point_list.size() < blocked_set.size()) {
            list<vector<int>> new_point_list;
            for (const auto point : point_list) {
                if (check_point(vector<int> ({point[0] + 1, point[1]}), reached, new_point_list, end_coord)) return 1;
                if (check_point(vector<int> ({point[0] - 1, point[1]}), reached, new_point_list, end_coord)) return 1;
                if (check_point(vector<int> ({point[0], point[1] + 1}), reached, new_point_list, end_coord)) return 1;
                if (check_point(vector<int> ({point[0], point[1] - 1}), reached, new_point_list, end_coord)) return 1;
            }
            if (new_point_list.empty()) {
                return -1;
            } else {
                point_list = new_point_list;
            }
        }
        return 0;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<long long> blocked_set;
        for (const auto point : blocked) {
            blocked_set.insert(point[0] * 1e6 + point[1]);
        }
        int from_source = check_start(source, target, blocked_set);
        if (from_source == 1) {
            return true;
        } else if (from_source == -1) {
            return false;
        }
        return check_start(target, source, blocked_set) >= 0;
    }
};


int main() {
    vector<vector<int>> blocked = {{0,3},{1,0},{1,1},{1,2},{1,3}};
    vector<int> source = {0,0};
    vector<int> target = {0,2};
    Solution solution;
    cout << solution.isEscapePossible(blocked, source, target) << endl;
    return 0;
}
