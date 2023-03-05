#include "debug_helper.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int length = 0;
        ListNode* now = head;
        while (now) {
            now = now->next;
            length ++;
        }
        if (length <= 1) {
            return true;
        }
        int mid_left = (length >> 1) - 1;
        int mid_right = (length >> 1) + (length & 1);
        // cout << length << ":" << mid_left << "-" << mid_right << endl;
        int index = 0;
        now = head;
        ListNode* next = head->next;
        while (index < mid_left) {
            ListNode* new_next = next->next;
            next->next = now;
            now = next;
            next = new_next;
            index ++;
        }
        head->next = NULL;
        if (length & 1) {
            next = next->next;
        }
        while (now && next) {
            if (now->val != next->val) {
                return false;
            } else {
                now = now->next;
                next = next->next;
            }
        }
        return true;
    }
};

int main() {
    vector<ListNode> node_list= {1,2,3,3,1};
    for (int i = 1; i < node_list.size(); i++) {
        node_list[i - 1].next = &(node_list[i]);
    }
    Solution solution;
    cout << solution.isPalindrome(&(node_list[0])) << endl;
    return 0;
}
