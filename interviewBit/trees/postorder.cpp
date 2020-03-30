#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> postorderTraversal(TreeNode* A) {
    stack<TreeNode*> nodeStack;
    vector<int> ret;
    if(A==NULL)
        return ret;
    nodeStack.push(A);
    while(!nodeStack.empty()) {
        TreeNode* node= nodeStack.top();  
        ret.push_back(node->val);
        nodeStack.pop();
        if(node->left)
            nodeStack.push(node->left);
        if(node->right)
            nodeStack.push(node->right);
    }
    reverse(ret.begin(),ret.end());
    return ret;
}