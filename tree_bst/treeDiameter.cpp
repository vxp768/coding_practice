/*
Given an undirected tree, return its diameter: the number of edges in a 
longest path in that tree.

The tree is given as an array of edges where edges[i] = [u, v] is a bidirectional edge 
between nodes u and v.  Each node has labels in the set {0, 1, ..., edges.length}.

Input: edges = [[0,1],[0,2]]
Output: 2

Input: edges = [[0,1],[1,2],[2,3],[1,4],[4,5]]
Output: 4
Explanation: 
A longest path of the tree is the path 3 - 2 - 1 - 4 - 5.

*/

class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> G;
        unordered_set<int> visited;
        
        for (int i=0; i<edges.size(); i++) {
            vector<int> e = edges[i];
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        int diam=0;
        for (auto it=G.begin(); it!=G.end(); it++){
            if(visited.find(it->first) == visited.end()){
                dfs(G, visited, it->first, diam);
            }
        }
        return diam -1; //num of edges not nodes.
    }
    int dfs(unordered_map<int, vector<int>>&G, unordered_set<int>& visited, int u, int& diam){
        
        int depth1=0, depth2=0;
        vector<int> adj;
        
        visited.insert(u);
        adj= G[u];    
        
        for (int i=0; i<adj.size(); i++) {
            int v = adj[i];
            if (visited.find(v) == visited.end()) {
                int d = dfs(G, visited, v, diam);
                if (d>=depth1) {
                    depth2 = depth1;
                    depth1 = d;
                } else if (d > depth2){
                    depth2 = d;
                }
            }
        }
        diam = max (diam, depth1 + depth2 +1);
        return depth1+1;
    }
};