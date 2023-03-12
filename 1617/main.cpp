#include "debug_helper.h"

using namespace std;

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> p_edge(n + 1, vector<int>());
        for (const auto edge : edges) {
            p_edge[edge[0]].push_back(edge[1]);
            p_edge[edge[1]].push_back(edge[0]);
        }
        // cout << p_edge << endl;
        for (int start = 1; start <= n; start ++) {
            list<int> check_point;
            vector<bool> checked(n + 1, false);
            check_point.push_back(start);
            checked[start] = true;
            int dist_now = 1;
            while (!check_point.empty()) {
                list<int> new_check_point;
                for (const auto point : check_point) {
                    for (const auto target : p_edge[point]) {
                        if (!checked[target]) {
                            dist[start][target] = dist_now;
                            new_check_point.push_back(target);
                            checked[target] = true;
                        }
                    }
                }
                dist_now ++;
                check_point = new_check_point;
            }
        }
        // cout << dist << endl;
		function<int(int, int, int, int)> dfs = [&](int u, int parent, int x, int y) -> int {
            if (dist[u][x] > dist[x][y] || dist[u][y] > dist[x][y]) {
                return 1;
            }
            if ((dist[u][y] == dist[x][y] && u < x) || (dist[u][x] == dist[x][y] && u < y)) {
                return 1;
            }
            int ret = 1;
            for (int v : p_edge[u]) {
                if (v != parent) {
                    ret *= dfs(v, u, x, y);
                }
            }
            if (dist[u][x] + dist[u][y] > dist[x][y]) {
                ret++;
            }
            return ret;
        };
        vector<int> ans(n - 1);
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n + 1; j++) {
                ans[dist[i][j] - 1] += dfs(i, -1, i, j);
            }
        }
        return ans;
    }
};

int main() {
	int n = 4;
	vector<vector<int>> edges = {{1,2},{2,3},{2,4}};
    Solution solution;
    cout << solution.countSubgraphsForEachDiameter(n, edges) << endl;
    return 0;
}
