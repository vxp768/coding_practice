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
// Prints postorder traversal from given inorder and preorder traversals 
void printPostOrder(int in[], int pre[], int n) 
{ 
    // The first element in pre[] is always root, search it 
    // in in[] to find left and right subtrees 
    int root = search(in, pre[0], n); 
  
    // If left subtree is not empty, print left subtree 
    if (root != 0) 
        printPostOrder(in, pre + 1, root); 
  
    // If right subtree is not empty, print right subtree 
    if (root != n - 1) 
        printPostOrder(in + root + 1, pre + root + 1, n - root - 1); 
  
    // Print root 
    cout << pre[0] << " "; 
} 
  

/* Tree can be re-constructed only if in-order is given as one of traversal
    1. inorder and preorder   2. inorder and postorder   3. inorder and level-order
*/
