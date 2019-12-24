/* Given inorder and pre-order traversals, construct binary tree */

Node *Buildbinarytree(vector<int> &inorder, vector<int> &preorder, int in_start, int in_end) {
    static int pre_index=0;
    if(in_start > in_end)
        return NULL;
    
    Node *node = new Node;
    node->data = preorder[pre_index];
    pre_index++;
    if(in_start==in_end)
        return node; //no child of this node
        
    int in_index = search(inorder, in_start, in_end, node->data);
    
    node->left  = Buildbinarytree(inorder, preorder, in_start, in_index-1);
    node->right = Buildbinarytree(inorder, preorder, in_index+1, in_end);
    
    return node;
}

/* Tree can be re-constructed only if in-order is given as one of traversal
    1. inorder and preorder   2. inorder and postorder   3. inorder and level-order
*/
