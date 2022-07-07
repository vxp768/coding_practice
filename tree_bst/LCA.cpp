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

//Method 3: Works even if only one node is present and also
// when one node(n1) is child of other node(n2) or vice-versa
// This function returns pointer to LCA of two given values n1 and n2. 
// v1 is set as true by this function if n1 is found 
// v2 is set as true by this function if n2 is found 
struct Node *findLCAUtil(struct Node* root, int n1, int n2, bool &v1, bool &v2) 
{ 
    // Base case 
    if (root == NULL) return NULL; 
  
    // If either n1 or n2 matches with root's key, report the presence 
    // by setting v1 or v2 as true and return root (Note that if a key 
    // is ancestor of other, then the ancestor key becomes LCA) 
    if (root->key == n1) { 
        v1 = true; 
        return root; 
    } 
    if (root->key == n2) { 
        v2 = true; 
        return root; 
    } 
    Node *left_lca  = findLCAUtil(root->left, n1, n2, v1, v2); 
    Node *right_lca = findLCAUtil(root->right, n1, n2, v1, v2); 
  
    // If both of the above calls return Non-NULL, then one key 
    // is present in once subtree and other is present in other, 
    // So this node is the LCA 
    if (left_lca && right_lca)  return root; 
  
    // Otherwise check if left subtree or right subtree is LCA 
    return left_lca? left_lca: right_lca; 
} 
  
// Returns true if key k is present in tree rooted with root 
bool find(Node *root, int k) 
{ 
    // Base Case 
    if (root == NULL) 
        return false; 
    // If key is present at root, or in left subtree or right subtree, 
    // return true;
    if (root->key == k || find(root->left, k) ||  find(root->right, k)) 
        return true; 
    return false; 
} 
// This function returns LCA of n1 and n2 only if both n1 and n2 are present 
// in tree, otherwise returns NULL; 
Node *findLCA(Node *root, int n1, int n2) 
{ 
    // Initialize n1 and n2 as not visited 
    bool v1 = false, v2 = false; 
    Node *lca = findLCAUtil(root, n1, n2, v1, v2); 
  
    // Return LCA only if both n1 and n2 are present in tree 
    if (v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1)) 
        return lca;
    return NULL; 
} 

//        LCA  in BST
Node *LCA_BST(Node *root, Node *n1, Node *n2){
    if(root == NULL)
        return NULL:
    while(1 && root) {
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