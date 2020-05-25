/*
 * Non recursive tree traversal using Stack
 * Pre order:  used to make copy of tree,  used to get prefix expression of tree
 * In Order:   gives BST in sorted order
 * Post Order: used to delete the tree, used to get postfix expression
 */
void non_recursive_in_order (Node *root) {
    stack<Node*> S;
    while(1) {
        while(root){
            S.push(root);
            root = root->left;
        }
        if (S.empty()) {
            return;
        }
        Node *node = S.top(); 
        S.pop();
        //Process the node
        printf("data: %d", node->data);
        root = node->right;
    }
}
void non_recursive_pre_order (Node *root) {
    stack<Node*> S;
    while(1) {
        while(root){
            //Process the node
            printf("data: %d", root->data);
            S.push(root);
            root = root->left;
        }
        if (S.empty()) {
            return;
        }
        Node *node = S.top(); 
        S.pop();
        root = node->right;
    }
}
/* This is tricky since both child returns to node, and node should be 
   processed after returning from right child
   It has non-tail recursion: there is an extra statement after the final recursive call to itself
*/
//Method1: using two stacks  https://www.geeksforgeeks.org/iterative-postorder-traversal/
void postOrderIterative(Node* root) { 
    if (root == NULL) 
        return; 
    stack<Node *> s1, s2; 
    s1.push(root); 
    Node* node; 
    while (!s1.empty()) { 
        node = s1.top();
        s1.pop();
        s2.push(node);  // S2 stores the node in reverse order of actual post-order traversal
        // Push left and right children of removed item to s1 
        if (node->left)
            s1.push(node->left); 
        if (node->right) 
            s1.push(node->right); 
    } 
    while (!s2.empty()) { 
        node = s2.top(); 
        s2.pop(); 
        cout << node->data << " "; 
    } 
} 
//Method 2: using 1 stack
void postOrderIterative(Node* root) { 
    // Check for empty tree 
    if (root == NULL) 
        return; 
      
    stack<Node *> S; 
    do { 
        // Move to leftmost node 
        while (root) {
            if (root->right) 
                S.push(root->right); 
            S.push(root); 
            root = root->left; 
        } 
  
        // Pop an item from stack and set it as root     
        root = S.top(); 
        S.pop();
        // If the popped item has a right child and the right child is not 
        // processed yet, then make sure right child is processed before root 
        if (root->right && S.top() == root->right) { 
            S.pop();  // remove right child from stack 
            S.push(root);  // push root back to stack 
            root = root->right; // change root so that the right child is processed next 
        } else { 
            printf("%d ", root->data); 
            root = NULL; 
        } 
    } while (!S.empty()); 
}