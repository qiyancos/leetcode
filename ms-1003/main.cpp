#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int lp = 0;
        int rp = n - 1;
        int mid = (lp + rp) >> 1;
        while (lp <= rp) {
            mid = (lp + rp) >> 1;
            cout << lp << ',' << mid << '@' << arr[mid] << ',' << rp << endl;
            if (target == arr[mid]) {
                if (arr[0] == target) {
                    return 0;
                }
                while (arr[mid] == target && mid > 0) {
                    mid --;
                }
                return mid + 1;
            } else if (arr[mid] < arr[rp]) {
                if (target > arr[mid] && target <= arr[rp]) {
                    lp = mid + 1;
                } else {
                    rp = mid - 1;
                }
            } else if (arr[mid] > arr[rp]) {
                if (target < arr[mid] && target >= arr[lp]) {
                    rp = mid - 1;
                } else {
                    lp = mid + 1;
                }
            } else {
                rp --;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> arr = {1,1,1,1,1,2,1,1,1};
    Solution solution;
    cout << solution.search(arr, 2) << endl;
    return 0;
}
