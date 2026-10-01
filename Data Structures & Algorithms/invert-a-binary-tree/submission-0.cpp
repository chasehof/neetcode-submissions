/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }


    void dfs(TreeNode* root) {
        if(!root) {
            return;
        }
        if(root->left && root->right){
        auto leftval{root->left};

        root->left = root->right;

        root->right = leftval;
        }
        else if (root->left && !root->right){
            root->right = root->left;
            root->left = nullptr;
        }
        else if (!root->left && root->right) {
            root->left = root->right;
            root->right = nullptr;
        }

        dfs(root->left);
        dfs(root->right);

        return;
    }

};


//              4
//     2                 7
// 1      3           6     9

