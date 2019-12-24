//Binary Tree structurally same
int same_structure(Node *root1, Node *root2) {
    if(root1==NULL &&root2==NULL)
        return 1;
    if(root1==NULL || root2==NULL)
        return 0;
    
    return (root1->data==root2->data && same_structure(root1->left, root2->left) &&
                                        same_structure(root1->right, root2->right));
}

//Binary Tree convert to it's mirror
void mirror(Node *root) {
    if(root==NULL)
        return;
    mirror(root->left);
    mirror(root->right);
    Node *tmp=root->left;
    root->left = root->right;
    root->right = tmp;
}

//Check if trees are mirror image
bool check_mirror(Node *root1, Node *root2) {
    if(root1==NULL && root2==NULL)
        return true;
    if(root == NULL || root2==NULL)
        return false;
    
    if(root1->data != root2->data)
        return false;
    return check_mirror(root1->left, root2->right) && check_mirror(root1->right, root2->left);
}

