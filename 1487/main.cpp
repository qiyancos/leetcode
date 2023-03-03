#include "debug_helper.h"

using namespace std;

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> name_count;
        vector<string> result;
        for (const auto name : names) {
            if (name_count.find(name) == name_count.end()) {
                name_count[name] = 0;
                result.push_back(name);
            } else {
                name_count[name] += 1;
                string new_name = name + "(" + to_string(name_count[name]) + ")";
                while (name_count.find(new_name) != name_count.end()) {
                    name_count[name] += 1;
                    new_name = name + "(" + to_string(name_count[name]) + ")";
                }
                result.push_back(new_name);
                name_count[new_name] = 0;
            }
        }
        return result;
    }
};

int main() {
	vector<string> names = {"pes","gta","gta(1)","gta(2)","gta(1)", "gta", "gta(2)"};
    Solution solution;
    cout << solution.getFolderNames(names) << endl;
    return 0;
}
