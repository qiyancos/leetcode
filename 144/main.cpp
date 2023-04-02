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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (! root) {
            return result;
        }
        result.push_back(root->val);
        if (root->left) {
            vector<int> left = preorderTraversal(root->left);
            result.insert(result.begin() + 1, left.begin(), left.end());
        }
        if (root->right) {
            vector<int> right = preorderTraversal(root->right);
            result.insert(result.end(), right.begin(), right.end());
        }
        return result;
    }
};

int main() {
    TreeNode* a = new TreeNode(3, nullptr, nullptr);
    TreeNode* b = new TreeNode(2, a, nullptr);
    TreeNode* c = new TreeNode(1, nullptr, b);
    Solution solution;
    cout << solution.preorderTraversal(c) << endl;
    return 0;
}
