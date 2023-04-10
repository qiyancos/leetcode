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

#define Node pair<int, TreeNode*>
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        vector<Node> tree;
        vector<TreeNode*> nodes_now = {root};
        while (!nodes_now.empty()) {
            vector<TreeNode*> nodes_next;
            for (const auto node : nodes_now) {
                tree.push_back(Node(node->val, node));
                if (node->left) {
                    nodes_next.push_back(node->left);
                }
                if (node->right) {
                    nodes_next.push_back(node->right);
                }
            }
            nodes_now = nodes_next;
        }
        sort(tree.begin(), tree.end(), [](const Node& a, const Node& b)->bool{return a.first > b.first;});
        int sum = 0;
        int check_val = -10001;
        for (const auto& node : tree) {
            if (node.first != check_val) {
                for (auto& same_node : nodes_now) {
                    same_node->val = sum;
                }
                nodes_now.clear();
                check_val = node.first;
            }
            sum += node.first;
            nodes_now.push_back(node.second);
        }
        for (const auto& same_node : nodes_now) {
            same_node->val = sum;
        }
        return root;
    }
};

int main() {
    TreeNode* n1 = new TreeNode(3, nullptr, nullptr);
    TreeNode* n2 = new TreeNode(2, nullptr, n1);
    TreeNode* n3 = new TreeNode(0, nullptr, nullptr);
    TreeNode* n4 = new TreeNode(1, n3, n2);
    TreeNode* n5 = new TreeNode(8, nullptr, nullptr);
    TreeNode* n6 = new TreeNode(7, nullptr, n5);
    TreeNode* n7 = new TreeNode(5, nullptr, nullptr);
    TreeNode* n8 = new TreeNode(6, n7, n6);
    TreeNode* n9 = new TreeNode(4, n4, n8);
    Solution solution;
    solution.convertBST(n9);
    vector<int> tree;
    vector<TreeNode*> nodes_now = {n9};
    while (!nodes_now.empty()) {
        vector<TreeNode*> nodes_next;
        for (const auto node : nodes_now) {
            tree.push_back(node->val);
            if (node->left) {
                nodes_next.push_back(node->left);
            }
            if (node->right) {
                nodes_next.push_back(node->right);
            }
        }
        nodes_now = nodes_next;
    }
    cout << tree << endl;
    return 0;
}
