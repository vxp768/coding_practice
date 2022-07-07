
/* Width of tree or Longest path between two nodes*/

int diameter(Node *root, int *height) {
    if(root==NULL) {
        *height = 0;
        return 0;
    }
    int ld=0, rd=0, lh=0, rh=0;
    ld = diameter(root->left, &lh);
    rd = diameter(root->right, &rh);
    
    *height = max(lh, rh)+1;
    
    return max(lh+rh+1, max(ld,rd));
}


class Solution {
    int diam=INT_MIN;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        //MAX of ( ( height of left and right subtree +1), max(diam_left_trees, diam_right_trees) )
        rec(root);
        return diam-1; //-1 as diam = num of edges in leetcode
    }
    int rec(TreeNode *root) {
        if (root==NULL)
            return 0;
        int l_h=0, r_h=0;
        l_h = rec(root->left);
        r_h = rec(root->right);
        diam = max(diam, l_h+r_h+1);
        return max(l_h, r_h) + 1;
    }
    
};