/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //RECURSIVE solution
 
class Codec {
public:

       // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";
        //pre-order format
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return mydeserialize(data);
    }
    TreeNode* mydeserialize(string& data) {
        if (data[0]=='#') {
            if(data.size() > 1) data = data.substr(2);
            return nullptr;
        } else {
            TreeNode* node = new TreeNode(helper(data));
            node->left = mydeserialize(data);
            node->right = mydeserialize(data);
            return node;
        }
    }
private:
    int helper(string& data) {
        int pos = data.find(',');
        int val = stoi(data.substr(0,pos));
        data = data.substr(pos+1);
        return val;
    }
};


/// LEVEL ORDER TRAVERSAL.....memory limit exceed as lot of null is being put at end
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> Q;
        string result="";
        if (root==NULL) return "";
        Q.push(root);
        while(!Q.empty()) {
            TreeNode *node = Q.front();
            Q.pop();
            if (node){
                result = result + to_string(node->val)+',';
                Q.push(node->left);
                Q.push(node->right);
            } else {
                result = result + "null,";
            }
        }
        cout<<result<<endl;
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root=NULL;
        TreeNode *node=NULL;
        queue<TreeNode*> Q;
        if(data.size() == 0) return root;
        
        int pos = data.find(',');
        root = new TreeNode(stoi(data.substr(0,pos)));
        data = data.substr(pos+1);
        Q.push(root);
        string tmp="";
        while(!Q.empty() && data.size() >1){
            node = Q.front();
            Q.pop();
            
            pos = data.find(',');
            tmp = data.substr(0,pos);
            if (tmp == "null"){
                node->left  = NULL;
            } else {
                node->left  = new TreeNode(stoi(tmp));
                Q.push(node->left);
            }
            data = data.substr(pos+1);
            if (data.substr(pos).size() <= 1)
                break;
           
            pos = data.find(',');
            tmp = data.substr(0, pos);
            if (tmp == "null"){
                node->right = NULL;
            } else {
                node->right = new TreeNode(stoi(tmp)); 
                Q.push(node->right);
            }
            data = data.substr(pos+1);
            if (data.substr(pos).size() <= 1)
                break;
        }    
        return root;
    }
};