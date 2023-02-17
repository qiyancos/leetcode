#include "debug_helper.h"

using namespace std;

map<char, vector<int>> alpha_map;
vector<int> getAlphaCoord(char alpha) {
    vector<int> coord;
    coord.push_back((alpha - 'a') / 5);
    coord.push_back((alpha - 'a') % 5);
    return coord;
}

class Solution {
public:
    Solution() {
        for (char alpha = 'a'; alpha <= 'z'; alpha ++){
            alpha_map[alpha] = getAlphaCoord(alpha);
        }
    }

    string alphabetBoardPath(string target) {
        string path = "";
        char last_alpha = 'a';
        for (const char &alpha : target) {
            int last_x = alpha_map[last_alpha][1];
            int last_y = alpha_map[last_alpha][0];
            int now_x = alpha_map[alpha][1];
            int now_y = alpha_map[alpha][0];
            int dx = now_x - last_x;
            int dy = now_y - last_y;
            if (dy < 0) {
                path += dy != 0 ? string(abs(dy), 'U') : "";
                path += dx != 0 ? string(abs(dx), dx < 0 ? 'L' : 'R') : "";
            } else {
                path += dx != 0 ? string(abs(dx), dx < 0 ? 'L' : 'R') : "";
                path += dy != 0 ? string(abs(dy), 'D') : "";
            }
            path += "!";
            last_alpha = alpha;
        }
        return path;
    }
};

int main() {
    string input = "leetcode";
    Solution solution;
    cout << solution.alphabetBoardPath(input) << endl;
    return 0;
}
