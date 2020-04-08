/* Insert / Delete BST */
Node *Insert(Node *root int data) {
    if(root == NULL) {
        Node *node = new Node;
        node->data = data;
        node->left = node->right = NULL;
    }
    if(data < root->data)
        root->left  = Insert(root->left, data);
    if(data > root->data)
        root->right = Insert(root->right, data);
    return node;
}

/*  1. node has no child...just delete that node
 *  2. node has only one child...delete that node and make its parent as parent of its single child
 *  3. node has both child...replace node with max in left subtree or min in right subtree
 *  return new root if needed
 */
Node *Delete(Node *root, int data) {
    if(root==NULL){
        cout<<"node not found"<<endl;
        return NULL;
    }
    if(data < root->data) {
        root->left = Delete(root->left, data);
    } else if (data > root->data) {
        root->right = Delete(root->right, data);
    } else { //found the node
        if(root->left && root->right) { //both child exist
            Node *tmp = FindMax(root->left);  //can use aswell FindMin(root->right)
            root->data = tmp->data;
            root->left = Delete(root->left, tmp->data);   //can use Delete(root->right, tmp->data);
        } else { //one child or no child
            Node *tmp = root;
            if(root->left==NULL)
                root = root->right;
            if(root->right == NULL)
                root = root->left;
            delete(tmp);
        }
    }
    return root;
}
Node *FindMin(Node *root) {
    if(root==NULL)
        return NULL;
    while(root->left){
        root = root->left;
    }
    /* //recursive method
     if(root->left == NULL){
        return root;
     } else {
        return FindMin(root->left);
     }
     */
    return root;
}
Node *FindMax(Node *root) {
    if(root==NULL)
        return NULL;
    while(root->right){
        root = root->right;
    }
    /* //recursive method
     if(root->right == NULL){
        return root;
     } else {
        return FindMin(root->right);
     }
     */
    return root;
}