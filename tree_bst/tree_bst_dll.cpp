/* Binary tree to DLL 
 * other methods
 * https://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
 * https://www.geeksforgeeks.org/convert-a-given-binary-tree-to-doubly-linked-list-set-4/
 * 
 * */
//Method 1
class Solution {
    Node *first, *last;
public:
    Node* treeToDoublyList(Node* root) {
        first = NULL, last = NULL;
        if(root == NULL)
            return NULL;
        rec(root);
        first->left = last;
        last->right = first;
        return first;
    }
    void rec(Node *root){
        if(root==NULL)
            return;
        rec(root->left);
        if (last){
            last->right = root;
            root->left = last;
        } else {
            first = root;
        }
        last = root;
        rec(root->right);
    }
};

//Method 2
/* 1. Do inorder traversal....push nodes in vector<Node*>
 * 2. Iterate through vector and fix the left and right pointers
 * https://www.geeksforgeeks.org/convert-a-given-binary-tree-to-circular-doubly-linked-list-set-2/
 * 
 */
  
 
/* BST to DLL */