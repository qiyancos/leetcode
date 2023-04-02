#include "debug_helper.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool checkTree(TreeNode* root) {
        return root->val == root->left->val + root->right->val;
    }
};

int main() {
    TreeNode* a = new TreeNode(4, nullptr, nullptr);
    TreeNode* b = new TreeNode(6, nullptr, nullptr);
    TreeNode* c = new TreeNode(10, a, b);
    Solution solution;
    cout << solution.checkTree(c) << endl;
    return 0;
}
