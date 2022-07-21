/*
Runtime: 18 ms, faster than 15.18% of C online submissions for Validate Binary Search Tree.
Memory Usage: 8.6 MB, less than 82.79% of C online submissions for Validate Binary Search Tree.
*/
bool checkValid(struct TreeNode* root, long low, long high) {
    if(!root)return true;
    if(root->val <= low || root->val >= high)return false;
    return checkValid(root->left,low,root->val)&&checkValid(root->right,root->val,high);
}

bool isValidBST(struct TreeNode* root){
    if(!root)return false;
    return checkValid(root->left, LONG_MIN, root->val) && checkValid(root->right,root->val,LONG_MAX);
}
