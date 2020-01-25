
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

