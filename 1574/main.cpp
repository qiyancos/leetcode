#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int size = arr.size();
        if (size == 1) {
            return 0;
        }
        int right = size - 2;
        int result = 1;
        while (right >= 0) {
            if (arr[right + 1] >= arr[right]) {
                right--;
                result ++;
            } else {
                break;
            }
        }
        right ++;
        if (right == 0) {
            return 0;
        }
        int max_r = result;
        int left = 0;
        while (left < size) {
            if (left == 0 || arr[left] >= arr[left - 1]) {
                result ++;
                while (right < size && arr[right] < arr[left]) {
                    result --;
                    right ++;
                }
                cout << left << "-" << right << ":" << result << endl;
                max_r = max(result, max_r);
                left ++;
            } else {
                break;
            }
        }
        return size - max_r;
    }
};

int main() {
	// vector<int> input = {13,0,14,7,18,18,18,16,8,15,20};
	// vector<int> input = {1,2,3,10,4,2,3,5};
	vector<int> input = {10,13,17,21,15,15,9,17,22,22,13};
    Solution solution;
    cout << solution.findLengthOfShortestSubarray(input) << endl;
    return 0;
}
