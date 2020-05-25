/*
   Implement an iterator over a binary search tree (BST).
   Your iterator will be initialized with the root node of a BST.
   Calling next() will return the next smallest number in the BST.
*/

class BSTIterator {
    TreeNode *root_n;
    vector<int> arr;
    int it;
    int size;
public:
    BSTIterator(TreeNode* root) {
        root_n = root;
        it=-1;
        inorder(root);
        size = arr.size();
    }
    void inorder(TreeNode *root){
        if(root==NULL)
            return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    /** @return the next smallest number */
    int next() {
        return arr[++it];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (it<(size-1))
            return true;
        else
            return false;
    }
};