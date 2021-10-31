/*
 * Given the root of a binary tree, return the vertical order traversal of its nodes' values. 
 * (i.e., from TOP to BOTTOM, column by column).

 * If two nodes are in the same row and column, the 
 * order should be from     LEFT to RIGHT.....simple pre-order(DFS) won't work.
 */

///BFS soln
class Solution {
    map<int, vector<int>> mp;
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root==NULL)
            return result;
        int idx = 0;
        queue<pair<int, TreeNode*>> Q;
        TreeNode *node;
        Q.push({0, root});
        while(!Q.empty()){
            pair<int, TreeNode*> idx_node = Q.front();
            Q.pop();
            int idx = idx_node.first;
            node = idx_node.second;
            mp[idx].push_back(node->val);
            if (node->left){
                Q.push({idx-1, node->left});
            }
            if (node->right){
                Q.push({idx+1, node->right});
            }
        }
        for(auto it=mp.begin(); it!=mp.end(); it++){
            result.push_back(it->second);
        }
        return result;
    }
};

/*
   Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

   For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) 
   and (row + 1, col + 1) respectively.
   The root of the tree is at (0, 0).

   The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index 
   starting from the leftmost column and ending on the rightmost column.
   There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
*/
class Solution {
    map<int, map<int,set<int>>> mp; //map for x,y coordinates
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
      
        vector<vector<int>> result;
        rec(root, 0, 0);
        
        for(auto it=mp.begin(); it!= mp.end(); it++){
            map<int,set<int>> y_mp = it->second;
            vector<int> v;
            for(auto it=y_mp.begin(); it!=y_mp.end(); it++){
                set<int> s = it->second;
                for(auto it=s.begin(); it!=s.end(); it++){
                    v.push_back(*it);
                }
            }
            result.push_back(v);
        }
        return result;
    }
    void rec(TreeNode *root, int x, int y) {
        if(root==NULL)
            return;
        mp[x][y].insert(root->val);
        rec(root->left, x-1, y+1);
        rec(root->right, x+1, y+1);
    }
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        
        queue<pair< pair<int,int>,TreeNode*> > Q;
        pair< pair<int,int>,TreeNode*> col_row_node;
        pair<int,int> col_row;
        TreeNode *node;
        
        if (root == NULL)
            return result;
        Q.push({{0,0},root});
        
        while(!Q.empty()){
            col_row_node = Q.front();
            Q.pop();
            col_row = col_row_node.first;
            node    = col_row_node.second;
            mp[col_row.first][col_row.second].insert(node->val);
            if(node->left)
                Q.push({{col_row.first-1, col_row.second+1}, node->left});
            if(node->right)
                Q.push({{col_row.first+1, col_row.second+1}, node->right});
        }
        
        for(auto it=mp.begin(); it!=mp.end(); it++){
            map<int, multiset<int>> col_mp = it->second;
            vector<int> res_col;
            for(auto it=col_mp.begin(); it!=col_mp.end(); it++){
                multiset<int> res = it->second;                
                res_col.insert(res_col.end(), res.begin(), res.end());
            }
            result.push_back(res_col);
        }
        return result;
    }