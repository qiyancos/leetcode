#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        vector<int> result;
        vector<int> line(matrix[0].size(), 0);
        for (int x = 0; x < matrix.size(); x++) {
            int temp = 0;
            for (int y = 0; y < matrix[0].size(); y++) {
                temp ^= matrix[x][y];
                line[y] ^= temp;
                cout << x << "," << y << ":" << line[y] << endl;
                result.push_back(line[y]);
            }
        }
        sort(result.begin(), result.end(), [](const int& a, const int& b)->bool{return a > b;});
        return result[k - 1];
    }
};

int main() {
   	// vector<vector<int>> matrix = {{5,2}, {1,6}, {3,4}};
    vector<vector<int>> matrix = {{8,1,2,0,9,3,7,0,1,3,5,5,1,10,4,1,4,4,7,9,3,5,1},
                                  {2,5,9,10,9,2,3,6,1,1,5,9,3,5,4,2,10,1,7,0,3,8,2},
                                  {7,9,10,0,8,7,5,0,1,7,0,6,6,2,3,6,2,3,4,4,3,4,6},
                                  {6,4,5,0,4,3,8,2,0,10,6,1,5,1,2,9,7,5,3,10,8,3,6},
                                  {0,7,5,0,4,7,9,0,1,5,0,10,4,9,7,9,9,4,8,6,5,5,2},
                                  {2,2,5,7,6,9,6,3,7,1,8,3,2,1,3,1,0,9,4,7,3,5,6}};
    int k = 12;
    Solution solution;
    cout << solution.kthLargestValue(matrix, k) << endl;
    return 0;
}
