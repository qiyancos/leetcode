#include "debug_helper.h"

using namespace std;

class Solution {
public:

    int maxUniqueSplit(string s) {
        unordered_set<string> sub_str;
        int max_count = 0;
        dfs(s, max_count, sub_str, 0, s.length() - 1);
        return max_count;
    }

    void dfs(const string& s, int& max_count, unordered_set<string>& sub_str, int count_now, int pos) {
        if (pos + 1 + count_now <= max_count) {
            return;
        }
        for (int length = 1; length <= pos + 1; length++) {
            string new_sub_str = s.substr(pos - length + 1, length);
            if (sub_str.find(new_sub_str) == sub_str.end()) {
                sub_str.insert(new_sub_str);
                cout << sub_str << ":" << pos - length << ":" << max_count << endl;
                if (pos - length >= 0) {
                    dfs(s, max_count, sub_str, count_now + 1, pos - length);
                } else {
                    max_count = max(max_count, count_now + 1);
                }
                sub_str.erase(new_sub_str);
            }
        }
    }
};

int main() {
	string input = "ababccc";
    Solution solution;
    cout << solution.maxUniqueSplit(input) << endl;
    return 0;
}
