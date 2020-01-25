/* Least common ancestor */

//METHOD 1: Record whole path from root to each node and then find first different entry in both paths.
bool findpath(Node *root, vector<int> &path, int data) {
    if(root==NULL)
        return false;
    path.push_back(root->key); 
    if(root->key == k) {
        return true;
    } else {
        if(((findPath(root->left, path, k)==true)) || 
             (findPath(root->right, path, k)==true)) {
            return true;
        }
    }
    path.pop_back();
    return false;
}
int findLCA(Node *root, int n1, int n2) {
    if(root==NULL)
        return 0;
    vector<int> path1, path2;
    //if any one node not found return -1;
    if (!findpath(root, path1, n1) || !findpath(root, path2, n2))
        return -1;
    //both nodes found...scan through paths
    for(int i=0; i<path1.size() && i<path2.size(); i++){
        if(path1[i] != path2[i])
            break;
    }
    return path1[i-1];
}

//Method 2: assuming both nodes in tree
Node *LCA(Node *root, Node *node1, Node *node2) {
    if(root==NULL)
        return NULL;
    //if one node is ancestor of another node then ancestor is LCA
    //if other node is not present even then one node is returned as ancestor...correct ans would be to return NULL as in first method
    if(root==node1 || root==node2)
        return root;
    Node *left_lca = LCA(root->left, node1, node2);
    Node *right_lca = LCA(root->right, node1, node2);
    if(left_lca && right_lca)
        return root;   //this is LCA if one node in left subtree and another in right subtree
    return left_lca?left_lca:right_lca;    //LCA already found...keep returning it in recursion
}



//        LCA  in BST
Node *LCA_BST(Node *root, Node *n1, Node *n2){
    if(root == NULL)
        return NULL:
    while(1) {
        // find first node splitting the data in n1 and n2
        if((n1->data < root->data && n2->data > root->data) ||
           (n1->data > root->data && n2->data < root->data)) {
               return root;
        }
        //both n1 and n2 lie on same side of root
        if(n1->data < root->data)
            root = root->left;
        else
            root = root->right;
    }
}