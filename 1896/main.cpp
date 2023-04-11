#include "debug_helper.h"

using namespace std;

ass Solution {
public:
    int minOperationsToFlip(string expression) {
        // 数字栈
        vector<pair<int, int>> stack_num;
        // 符号栈
        vector<char> stack_op;

        auto op_and = [](int x1, int y1, int x2, int y2) -> pair<int, int> {
            return {min({x1 + x2, x1 + y2, y1 + x2}), y1 + y2};
        };

        auto op_or = [](int x1, int y1, int x2, int y2) -> pair<int, int> {
            return {x1 + x2, min({x1 + y2, y1 + x2, y1 + y2})};
        };

        // 尝试将数字栈顶的两个二元组和符号栈顶的运算符进行运算
        auto calc = [&]() {
            if (stack_num.size() >= 2 && (stack_op.back() == '|' || stack_op.back() == '&')) {
                auto [x1, y1] = stack_num.back();
                stack_num.pop_back();
                auto [x2, y2] = stack_num.back();
                stack_num.pop_back();

                auto [x_and, y_and] = op_and(x1, y1, x2, y2);
                auto [x_or, y_or] = op_or(x1, y1, x2, y2);
                
                if (stack_op.back() == '&') {
                    stack_num.emplace_back(min(x_and, x_or + 1), min(y_and, y_or + 1));
                }
                else {
                    stack_num.emplace_back(min(x_or, x_and + 1), min(y_or, y_and + 1));
                }
                stack_op.pop_back();
            }
        };
        
        for (char ch: expression) {
            if (ch == '(' || ch == '|' || ch == '&') {
                stack_op.push_back(ch);
            }
            else if (ch == '0') {
                stack_num.emplace_back(0, 1);
                calc();
            }
            else if (ch == '1') {
                stack_num.emplace_back(1, 0);
                calc();
            }
            else {
                assert(ch == ')');
                // 此时符号栈栈顶一定是左括号
                stack_op.pop_back();
                calc();
            }
        }

        return max(stack_num[0].first, stack_num[0].second);
    }
};

int main() {
	string in = "1&(0|1)";
    Solution solution;
    cout << solution.minOperationsToFlip(in) << endl;
    return 0;
}
