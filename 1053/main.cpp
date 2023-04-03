#include "debug_helper.h"

using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) {
            return arr;
        }
        for (int left = n - 2; left >= 0; left --) {
            int min_gap = 10000;
            int min_right = 0;
            for (int right = n - 1; right > left; right--) {
                if (arr[left] > arr[right] && arr[left] - arr[right] <= min_gap) {
                    min_gap = arr[left] - arr[right];
                    min_right = right;
                    // cout << left << "," << right << ":" << min_gap << endl;
                }
            }
            if (min_gap < 10000) {
                int temp = arr[left];
                arr[left] = arr[min_right];
                arr[min_right] = temp;
                return arr;
            }
        }
        return arr;
    }
};

int main() {
    vector<int> a = {1,9,4,7,7};
    Solution solution;
    cout << solution.prevPermOpt1(a) << endl;
    return 0;
}
