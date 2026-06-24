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
    bool bstcheck(TreeNode* root, int minR, int maxR){
        if(root == NULL) return true;
        if(root -> val >= maxR || root -> val <= minR) return false;
        return bstcheck(root -> left, minR, root->val) && bstcheck(root -> right, root->val, maxR);
    }
    bool isValidBST(TreeNode* root) {
        int minR = INT_MIN;
        int maxR = INT_MAX;
        return bstcheck(root, minR, maxR);
    }
};
