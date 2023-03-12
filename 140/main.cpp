#include "debug_helper.h"

using namespace std;

class Solution {
public:
    vector<string> find_sub(string s, set<string>& word_set) {
        //cout << s << endl;
        vector<string> result;
        for (int i = 1; i <= s.length(); i++) {
            string left = s.substr(0, i);
            if (word_set.find(left) != word_set.end()) {
                vector<string> sub_result = {""};
                if (i != s.length()) {
                    sub_result = find_sub(s.substr(i, s.length() - i), word_set);
                }
                for (const auto sub : sub_result) {
                    result.push_back(left + (sub == "" ? "" : " ") + sub);
                }
                // cout << left << ": " << sub_result << endl;
            }
        }
        return result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> word_set;
        word_set.insert(wordDict.begin(), wordDict.end());
        return find_sub(s, word_set);
    }
};

int main() {
	string s = "catsanddog";
	vector<string> word = {"cat", "cats", "and", "sand", "dog"};
    Solution solution;
    cout << solution.wordBreak(s, word) << endl;
    return 0;
}
