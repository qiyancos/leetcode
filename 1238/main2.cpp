#include "debug_helper.h"

using namespace std;

class Solution {
public:
    vector<int> getCircularArray(int n) {
        if (n == 1) {
            return {1, 0};
        }
        vector<int> sub_vec = getCircularArray(n - 1);
        vector<int> result = sub_vec;
        int add = (1 << (n - 1));
        for (int i = sub_vec.size() - 1; i >= 0; i --) {
            result.push_back(sub_vec[i] + add);
        }
        return result;
    }

    vector<int> circularPermutation(int n, int start) {
        int count = (1 << n);
        vector<int> circle = getCircularArray(n);
        // cout << circle << endl;
        vector<int> result;
        int index = 0;
        bool ready = false;
        while (true) {
            if (!ready && circle[index] == start) {
                ready = true;
            }
            if (ready) {
                if (result.size() == count) {
                    break;
                } else {
                    result.push_back(circle[index]);
                }
            }
            index ++;
            if (index == count) {
                index = 0;
            }
        }
        return result;
    }
};

int main() {
    int n = 3;
    int start = 2;
    Solution solution;
    cout << solution.circularPermutation(n, start) << endl;
    return 0;
}
