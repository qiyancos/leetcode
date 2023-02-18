#include "debug_helper.h"

using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int size = barcodes.size();
        unordered_map<int,int> map;//存数字出现次数
        for(auto b : barcodes)
            ++map[b];
        vector<pair<int,int>> slt;//将map数据转入vector数组进行排序
        for(auto it = map.begin(); it != map.end(); ++it) 
            slt.push_back({it -> first, it -> second});
        sort(slt.begin(), slt.end(), [](pair<int,int> lhs, pair<int,int> rhs) {
            return lhs.second > rhs.second;
        });
        int index = 0, res_index = 0;
        while(index < slt.size()) {//隔一填一，依此填入数据即可。
            barcodes[res_index] = slt[index].first;
            res_index += 2;
            --slt[index].second;
            if(!slt[index].second) ++index;
            if(res_index >= size) res_index = 1;
        }
        return barcodes;
    }
};

int main() {
    vector<int> input = {2,2,1,3};
    // vector<int> input = {1,1,1,1,2,2,3,3};
    // vector<int> input = {1,1,1,1,2,2,3};
    Solution solution;
    cout << solution.rearrangeBarcodes(input) << endl;
    return 0;
}
