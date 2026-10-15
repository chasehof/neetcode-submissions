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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(!root) {return false;}

        if(!subRoot) {return true;}


        if(isSametree(root, subRoot)){
            return true;
        }

        
        

       return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

    }

    bool isSametree(TreeNode* p, TreeNode* q) {
        if (!p && q) {
            return false;
        } else if (!q && p) {
            return false;
        } else if (!q && !p) {
            return true;
        }

        else {
            if (p->val != q->val) {
                return false;
            }

            else {
                if (!isSametree(p->left, q->left)) {
                    return false;
                }
                if (!isSametree(p->right, q->right)) {
                    return false;
                }
            }
        }

        return true;
    }

};
