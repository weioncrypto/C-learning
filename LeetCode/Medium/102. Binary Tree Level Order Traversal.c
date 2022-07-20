/*
Runtime: 6 ms, faster than 74.87% of C online submissions for Binary Tree Level Order Traversal.
Memory Usage: 8.2 MB, less than 53.89% of C online submissions for Binary Tree Level Order Traversal.
*/
void traverse(struct TreeNode* root, int** ret, int level, int *idx) {
    if(!root)return;

    // 若還沒有值則分配一個記憶體，若有值則重新分配記憶體
    if(idx[level] == 0)
        ret[level] = calloc(1, sizeof(int));
    else
        ret[level] = realloc(ret[level],sizeof(int) * (idx[level] + 1));
    ret[level][idx[level]] = root->val;
    idx[level]++;

    traverse(root->left, ret, level + 1, idx);
    traverse(root->right, ret, level + 1, idx);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int** ret = calloc(2000,sizeof(int*));
    int idx[2000] = {0};     // 告知現在特定深度的值有幾個了
    traverse(root, ret, 0, idx);

    *returnSize = 0;
    for(int i = 0 ; i < 2000 ; i++) {
        if(idx[i] == 0)
            break;
        (*returnSize)++;
    }

    (*returnColumnSizes) = calloc((*returnSize),sizeof(int));
    for(int i = 0 ; i < (*returnSize) ; i++) {
        (*returnColumnSizes)[i] = idx[i];
    }

    return ret;
}
