#include "debug_helper.h"

using namespace std;

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> word_score(words.size(), 0);
        vector<vector<int>> word_count(words.size(), vector<int>('z' + 1, 0));
        vector<int> letter_count('z' + 1, 0);
        for (auto const letter : letters) {
            letter_count[letter] ++;
        }
        for (int i = 0; i < words.size(); i ++) {
            for (auto const& letter : words[i]) {
                word_count[i][letter] ++;
                word_score[i] += score[letter - 'a'];
            }
            for (char j = 'a'; j <= 'z'; j++) {
                if (word_count[i][j] > letter_count[j]) {
                    word_score[i] = 0;
                    break;
                }
            }
        }
        int max_score = 0;
        for (int word_set = 1; word_set < (1 << words.size()); word_set ++) {
            vector<int> letter_count_now('z' + 1, 0);
            int score_now = 0;
            for (int i = 0; i < words.size(); i++) {
                if (word_set & (1 << i)) {
                    for (char j = 'a'; j <= 'z'; j++) {
                        letter_count_now[j] += word_count[i][j];
                    }
                    score_now += word_score[i];
                }
            }
            bool too_many = false;
            for (char j = 'a'; j <= 'z'; j++) {
                if (letter_count_now[j] > letter_count[j]) {
                    too_many = true;
                    break;
                }
            }
            max_score = max(max_score, too_many ? 0 : score_now);
        }
        return max_score;
    }
};

int main() {
    vector<string> words = {"xxxz", "ax", "bx", "cx"};
    vector<char> letters = {'z', 'a', 'b', 'c', 'x', 'x', 'x'};
    vector<int> score = {4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10};
    Solution solution;
    cout << solution.maxScoreWords(words, letters, score) << endl;
    return 0;
}
