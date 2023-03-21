#include "debug_helper.h"

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int total = 0;
        ListNode *left, *right;
        ListNode *start = head;
        while (head) {
            if (total == k - 1) {
                left = head;
            }
            head = head->next;
            total ++;
        }
        if (total & 1 && k == (total + 1) >> 1) {
            return start;
        }
        int gap = total - (k << 1) + 1;
        if (gap >= 0) {
            right = left;
        } else {
            right = start;
            gap = total - k;
        }
        // cout << total << ":" << gap << endl;
        while (gap--) {
            right = right->next;
        }
        total = right->val;
        right->val = left->val;
        left->val = total;
        return start;
    }
};

int main() {
    vector<int> input = {1,2,3,4,5};
    int k = 4;
    ListNode* next = nullptr;
    for (int i = input.size() - 1; i >= 0; i--) {
        next = new ListNode(input[i], next);
    }
    Solution solution;
    ListNode* result_node = solution.swapNodes(next, k);
    vector<int> result;
    while (result_node) {
        result.push_back(result_node->val);
        result_node = result_node->next;
    }
    cout << result << endl;
    return 0;
}
