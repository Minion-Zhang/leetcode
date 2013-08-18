/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Check NULL pointer
        if( p == NULL && q == NULL )
            return true;
        
        if( (p == NULL && q != NULL)
          ||(p != NULL && q == NULL) )
            return false;
        
        // Both not none, check it's value and subtree
        if( p->val != q->val )
            return false;
        else
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);        
        
    }
};