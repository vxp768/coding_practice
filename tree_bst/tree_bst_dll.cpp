/* Binary tree to DLL 
 * other methods
 * https://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
 * https://www.geeksforgeeks.org/convert-a-given-binary-tree-to-doubly-linked-list-set-4/
 * 
 * */
//Method 1
Node *FixLeftPtrs(Node *root) {   //Fix prev ptrs
    static Node *prev = NULL;
    if(root) {
        FixLeftPtrs(root->left);
        root->left = prev;
        prev = root;
        FixLeftPtrs(root->right);
    }
}
Node *FixRightPtrs(Node *root) {  //Fix next ptrs
    while(root->right) {
        root = root->right;
    }
    Node *next=NULL;
    while(root && root->left){
        next = root;
        root = root->left;    //goes to previous node in Dll
        root->right = next;
    }
    return root;
}
Node *binary_tree_to_DLL(Node *root) {
    FixLeftPtrs(root);
    return FixRightPtrs(root);
}
//Method 2...head points to head of DLL
void binary_tree_to_DLL(Node *root, Node **head) {
    static Node *prev=NULL;
    if(root==NULL)
        return;
    binary_tree_to_DLL(root->left);
    if(prev==NULL){
        *head = root;
    } else {
        prev->right = root;
        root->left  = prev;
    }
    prev = root;
    binary_tree_to_DLL(root->right, head);
}
//Method 3
/* 1. Do inorder traversal....push nodes in vector<Node*>
 * 2. Iterate through vector and fix the left and right pointers
 * https://www.geeksforgeeks.org/convert-a-given-binary-tree-to-circular-doubly-linked-list-set-2/
 * 
 */
  
 
/* BST to DLL */