/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given tree
     * @return: the number of uni-value subtrees.
     */
    int ctr = 0;
    
    int recurr(TreeNode *A){
        if(A == NULL) return 1;
        if(A->left == NULL && A->right == NULL){
            ctr++;
            return 1;
        }
        int l = 1, r = 1;
        if(A->left){
            l = recurr(A->left);
        }
        if(A->right){
            r = recurr(A->right);
        }
        if(l == -1 || r == -1){
            return -1;
        }
        if(A->left && (A->val != A->left->val)){
            return -1;
        }
        if(A->right && (A->val != A->right->val)){
            return -1;
        }
        ctr++;
        return 1;
    }
    
    int countUnivalSubtrees(TreeNode * root) {
        ctr = 0;
        recurr(root);
        return ctr;
    }
};