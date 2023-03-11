#include "debug_helper.h"

using namespace std;

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int size = array.size();
        unordered_map<int, int> min_index;
        unordered_map<int, int> max_index;
        min_index[0] = 0;
        max_index[0] = 0;
        vector<int> count(size + 1, 0);
        int num_count = 0;
        for (int i = 0; i < size; i++) {
            if (array[i][0] >= '0' && array[i][0] <= '9') {
                num_count ++;
            } else {
                num_count --;
            }
            if (min_index.find(num_count) == min_index.end()) {
                min_index[num_count] = i + 1;
            }
            max_index[num_count] = i + 1;
        }
        // cout << min_index << endl;
        // cout << max_index << endl;
        int start = 0;
        int max_size = 0;
        for (const auto max_item : max_index) {
            int right = max_item.second;
            int real_count = max_item.first;
            auto left = min_index.find(real_count);
            if (left == min_index.end() || left->second >= right) {
                continue;
            }
            // cout << real_count << ":" << left->second << ":" << right << endl;
            if (right - left->second > max_size || (
                    right - left->second == max_size && left->second < start)) {
                max_size = right - left->second;
                start = left->second;
            }
        }
        vector<string> result;
        for (int i = start; i < start + max_size; i++) {
            result.push_back(array[i]);
        }
        return result;
    }
};

int main() {
    // vector<string> input = {"A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"};
    // vector<string> input = {"A","D"};
    vector<string> input = {"42","10","O","t","y","p","g","B","96","H","5","v","P","52","25","96","b","L","Y","z","d","52","3","v","71","J","A","0","v","51","E","k","H","96","21","W","59","I","V","s","59","w","X","33","29","H","32","51","f","i","58","56","66","90","F","10","93","53","85","28","78","d","67","81","T","K","S","l","L","Z","j","5","R","b","44","R","h","B","30","63","z","75","60","m","61","a","5","S","Z","D","2","A","W","k","84","44","96","96","y","M"};
    // vector<string> input = {"52","3","v","71","J","A","0","v","51","E","k","H","96","21","W","59","I","V","s","59","w","X","33","29","H","32","51","f","i","58","56","66","90","F","10","93","53","85","28","78","d","67","81","T","K","S","l","L","Z","j","5","R","b","44","R","h","B","30","63","z","75","60","m","61","a","5"};
    Solution solution;
    cout << solution.findLongestSubarray(input) << endl;
    return 0;
}
