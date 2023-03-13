#include "debug_helper.h"

using namespace std;

class Solution {
public:
    string replaceSpaces(string S, int length) {
        string result;
        for (int i = 0; i < length; i++) {
            if (S[i] == ' ') {
                result += "%20";
            } else {
                result += S[i];
            }
        }
        return result;
    }
};

int main() {
    string S = "Mr John Smith     ";
    int length = 13;
    Solution solution;
    cout << solution.replaceSpaces(S, length) << endl;
    return 0;
}
