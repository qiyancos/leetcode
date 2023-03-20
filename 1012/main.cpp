#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int count_single(int n_size, int left, int last) {
        string left_str = to_string(left);
        vector<bool> checked(10, false);
        for (int i = 0; i < left_str.size(); i ++) {
            int num = left_str[i] - '0';
            if (checked[num]) {
                return 0;
            }
            checked[num] = true;
        }
        int result = 0;
        for (int i = last + 1; i <= 9; i++) {
            result += !checked[i];
        }
        // cout << left << last << " >> " << result << endl;
        return result;
    }

    int count(int n, unordered_map<int, int>& counted) {
        if (counted.find(n) != counted.end()) {
            return counted[n];
        }
        string n_str = to_string(n);
        int n_size = n_str.length();
        int result = n;
        if (n_size > 1) {
            result = count(pow(10, n_size - 1) - 1, counted) + 
                    (count(n / 10, counted) - count(pow(10, n_size - 2) - 1, counted)) *
                    (10 - n_size + 1);
            result -= count_single(n_size, n / 10, n % 10);
        }
        // cout << n << ": " << result << endl;
        counted[n] = result;
        return result;
    }

    int numDupDigitsAtMostN(int n) {
        unordered_map<int, int> counted;
        if (n <= 10) {
            return 0;
        } else {
            return n - count(n, counted);
        }
    }
};

int main() {
    int n = 1000;
    Solution solution;
    cout << solution.numDupDigitsAtMostN(n) << endl;
    return 0;
}
