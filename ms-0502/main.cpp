#include "debug_helper.h"

using namespace std;

union DOUBLE {
    double num;
    unsigned char bnum[8];
};

class Solution {
public:
    string printBin(double num) {
        union DOUBLE temp;
        temp.num = num;
        // for (int i = 0; i < 8; i++) {
        //    printf("%02x", temp.bnum[8 - i - 1]);
        //}
        //printf("\n");
        if (temp.bnum[0] != 0) {
            return "ERROR";
        } else {
            int ratio = (temp.bnum[7] << 4) + (temp.bnum[6] >> 4) - 1023;
            string result = "0.";
            while(++ratio) {
                result += "0"; 
            }
            result += "1";
            for (int j = 3; j >= 0; j--) {
                result += ((temp.bnum[6] >> j) & 1) ? "1" : "0";
            }
            for (int i = 5; i >= 0; i--) {
                for (int j = 7; j >= 0; j--) {
                    result += ((temp.bnum[i] >> j) & 1) ? "1" : "0";
                    if (result.length() == 32) {
                        break;
                    }
                }
                if (result.length() == 32) {
                    break;
                }
            }
            int last_one = 31;
            for (last_one = 31; last_one >= 2; last_one--) {
                if (result[last_one] != '0') {
                    break;
                }
            }
            return result.substr(0, last_one + 1);
        }
    }
};

int main() {
    double num = 0.025;
    //num = 0.6;
    Solution solution;
    cout << solution.printBin(num) << endl;
    return 0;
}
