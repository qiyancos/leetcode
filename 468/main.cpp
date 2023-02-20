#include "debug_helper.h"

using namespace std;

class Solution {
public:
    bool isV4Part(string input) {
        for (const auto single : input) {
            if (single < '0' || single > '9') {
                return false;
            }
        }
        if (input.length() > 3 || input.length() == 0) {
            return false;
        }
        if (input[0] == '0' && input.length() > 1) {
            return false;
        }
        if (input.length() == 3) {
            if (input[0] > '2') {
                return false;
            } else if (input[0] == '2') {
                if (input[1] > '5') {
                    return false;
                } else if (input[1] == '5' && input[2] > '5') {
                    return false;
                }
            }
        }
        return true;
    }

    bool isV6Part(string input) {
        return input.length() > 0 && input.length() <= 4;
    }

    string validIPAddress(string queryIP) {
        if (queryIP.length() > 39) {
            return "Neither";
        }
        int dot = 0;
        int colon = 0;
        int last_index = -1;
        for (int index = 0; index < queryIP.length(); index++) {
            char single = queryIP[index];
            if (single == '.') {
                if (dot == 3) {
                    return "Neither";
                }
                int length = index - last_index - 1;
                if (length > 3) {
                    return "Neither";
                } else if (!isV4Part(queryIP.substr(
                        last_index == -1 ? 0 : last_index + 1, length))) {
                    return "Neither";
                } else {
                    dot ++;
                    last_index = index;
                }
            } else if (single == ':') {
                if (colon == 7) {
                    return "Neither";
                }
                int length = index - last_index - 1;
                if (length > 4) {
                    return "Neither";
                } else if (!isV6Part(queryIP.substr(
                        last_index == -1 ? 0 : last_index, length))) {
                    return "Neither";
                } else {
                    colon ++;
                    last_index = index;
                }
            } else if ((single >= 'a' && single <= 'f') || (single >= 'A' && single <= 'F')) {
                if (dot) {
                    return "Neither";
                }
            } else if (single < '0' || single > '9' ) {
                return "Neither";
            }
        }
        if (dot && colon) {
            return "Neither";
        } else if (dot == 3 && isV4Part(queryIP.substr(last_index + 1))) {
            return "IPv4";
        } else if (colon == 7 && isV6Part(queryIP.substr(last_index + 1))) {
            return "IPv6";
        }
        return "Neither";
    }
};

int main() {
	string input = "200k:0db8:85a3:0:0:8A2E:0370:7334";
    input = "192.168.1.277:2938";
    input = "1e1.2.3.4";
    input = "1.2.33";
    Solution solution;
    cout << solution.validIPAddress(input) << endl;
    return 0;
}
