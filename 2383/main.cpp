#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int result = 0;
        for (const auto e : energy) {
            result += e;
        }
        result -= initialEnergy - 1;
        if (result < 0) {
            result = 0;
        }
        for (const auto ex : experience) {
            if (initialExperience <= ex) {
                result += (ex - initialExperience + 1);
                initialExperience = (ex << 1) + 1;
            }  else {
                initialExperience += ex;
            }
        }   
        return result;
    }
};

int main() {
    int a = 1;
    int b = 1;
    vector<int> c = {1,1,1,1};
    vector<int> d = {1,1,1,50};
    Solution solution;
    cout << solution.minNumberOfHours(a,b,c,d) << endl;
    return 0;
}
