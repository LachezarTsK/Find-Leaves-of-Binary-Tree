
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    
public:

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> leaves;
        collectLeaves(root, leaves);
        return leaves;
    }

    int collectLeaves(TreeNode* node, vector<vector<int>>&leaves) {
        if (node == nullptr) {
            return -1;
        }

        int level = 1 + max(collectLeaves(node->left, leaves), collectLeaves(node->right, leaves));

        if (level == leaves.size()) {
            leaves.push_back(vector<int>());
        }
        leaves[level].push_back(node->val);

        return level;
    }
};
