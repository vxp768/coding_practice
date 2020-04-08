/* FOR BST
 * Successor:   1. If right child not NULL....then find min in the right sub-tree.
                2. If right child is NULL, then find last ancestor where the path took left.
                    Now after finding the node x, recur­sion will back­track to the root. 
                    Every recursive call will return the node itself to the calling function, 
                    we will store this in a temporary node say temp.
                    Now, when it back­tracked to its par­ent which will be root now, 
                    check whether root.left = temp, if not , keep going up.
                    https://www.geeksforgeeks.org/inorder-succesor-node-binary-tree/
*/
//   Successor in BST
struct node * inOrderSuccessor(struct node *root, struct node *n) { 
    // step 1 of the above algorithm 
    if( n->right != NULL ) 
        return minValue(n->right); 

    struct node *succ = NULL; 

    // Start from root and search for successor down the tree 
    while (root != NULL) { 
        if (n->data < root->data) { 
            succ = root; //keeping track of last left child traversal
            root = root->left; 
        } else if (n->data > root->data) 
            root = root->right; 
        else
            break; //break when the node is found
    }
    return succ; 
} 

// Function that finds predecessor and successor of key in BST. 
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) 
{ 
    if (root == NULL) 
        return; 
  
    // Search for given key in BST. 
    while (root != NULL) { 
  
        // If root is given key. 
        if (root->key == key) { 
            // the minimum value in right subtree is predecessor. 
            if (root->right) { 
                suc = root->right; 
                while (suc->left) 
                    suc = suc->left; 
            }
            // the maximum value in left subtree is successor. 
            if (root->left) { 
                pre = root->left; 
                while (pre->right) 
                    pre = pre->right; 
            } 
  
            return; 
        }
        
        // If key is greater than root, then key lies in right subtree. Root 
        // could be predecessor if left subtree of key is null. 
        else if (root->key < key) { 
            pre = root; 
            root = root->right; 
        } 
        // If key is smaller than root, then key lies in left subtree. Root 
        // could be successor if right subtree of key is null. 
        else { 
            suc = root; 
            root = root->left; 
        } 
    } 
}