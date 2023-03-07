#include "debug_helper.h"

using namespace std;

class Solution {
public:
    vector<string> search_sub(string expression) {
        // 对于纯字母字符串，直接返回
        if (expression.find(',') == string::npos && expression.find('{') == string::npos) {
            return {expression};
        }
        // 处理顶级逗号列表
        int last_check = -1;
        int left_count = 0;
        vector<string> sub_str;
        for (int i = 0; i < expression.length(); i++) {
            const char item = expression[i];
            if (item == ',' && left_count == 0) {
                sub_str.push_back(expression.substr(
                        last_check + 1, i - last_check - 1));
                last_check = i;
            } else if (item == '{') {
                left_count ++;
            } else if (item == '}') {
                left_count --;
            }
        }
        if (last_check != expression.length()) {
            sub_str.push_back(expression.substr(
                    last_check + 1, expression.length() - last_check - 1));
        }
        // cout << expression << " >> SPLIT: " << sub_str << endl;
        // 处理子字符串
        vector<string> result;
        if (sub_str.size() == 1) {
            vector<vector<string>> sub_result;
            last_check = -1;
            left_count = 0;
            for (int i = 0; i < expression.length(); i++) {
                const char item = expression[i];
                if (item == ',' && left_count == 0) {
                    sub_result.push_back({expression.substr(
                            last_check + 1, i - last_check - 1)});
                    last_check = i;
                } else if (item == '{') {
                    if (left_count == 0 && i != last_check + 1) {
                        sub_result.push_back({expression.substr(
                                last_check + 1, i - last_check - 1)});
                        last_check = i - 1;
                    }
                    left_count ++;
                } else if (item == '}') {
                    if (left_count == 1) {
                        sub_result.push_back(search_sub(expression.substr(
                                last_check + 2, i - last_check - 2)));
                        last_check = i;
                    }
                    left_count --;
                }
            }
            if (last_check != expression.length() - 1) {
                sub_result.push_back({expression.substr(
                        last_check + 1, expression.length() - last_check - 1)});
            }
            // cout << expression << " >> SUB: " << sub_result << endl;
            for (const auto sub_list : sub_result) {
                if (result.empty()) {
                    result = sub_list;
                } else {
                    vector<string> new_result;
                    for (const auto left : result) {
                        for (const auto right : sub_list) {
                            new_result.push_back(left + right);
                        }
                    }
                    result = new_result;
                }
            }
        } else {
            for (const auto sub : sub_str) {
                vector<string> sub_result = search_sub(sub);
                result.insert(result.end(), sub_result.begin(), sub_result.end());
            }
        }
        // cout << expression << ": " << result << endl;
        return result;
    }

    vector<string> braceExpansionII(string expression) {
        vector<string> result = search_sub(expression);
        // 去重
        vector<string> real_result;
        unordered_set<string> result_set;
        for (const auto item : result) {
            if (result_set.find(item) == result_set.end()) {
                result_set.insert(item);
                real_result.push_back(item);
            }
        }
        sort(real_result.begin(), real_result.end());
        return real_result;
    }
};

int main() {
    string input = "zz{a,b}{c,a{d,eo,il}{io,ki}kk{jl,h}}ll";
    cout << input << endl;
    Solution solution;
    cout << solution.braceExpansionII(input) << endl;
    return 0;
}
