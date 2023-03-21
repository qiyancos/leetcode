#include "debug_helper.h"

using namespace std;

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
		return {celsius + 273.15, celsius * 1.8 + 32.0};
    }
};

int main() {
	double input = 122.11;
    Solution solution;
    cout << solution.convertTemperature(input) << endl;
    return 0;
}
