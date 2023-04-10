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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* node_last = nullptr;
        ListNode* node_now = head;
        while (node_now) {
            ListNode* temp;
            temp = node_now->next;
            node_now->next = node_last;
            node_last = node_now;
            node_now = temp;
        }
        head = node_last;
        stack<int> down;
        vector<int> result;
        while (head) {
            while (!down.empty() and down.top() <= head->val) {
                down.pop();
            }
            result.push_back(down.empty() ? 0 : down.top());
            down.push(head->val);
            head = head->next;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    vector<int> input = {2,7,4,3,5};
    ListNode* last = nullptr;
    ListNode* head = nullptr;
    for (const auto item : input) {
        if (last) {
            last->next = new ListNode(item);
            last = last->next;
        } else {
            head = last = new ListNode(item);
        }
    }
    Solution solution;
    cout << solution.nextLargerNodes(head) << endl;
    return 0;
}
