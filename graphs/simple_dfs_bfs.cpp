class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> G(n,vector<int>{});
        vector<int> visited(n,-1);
        int count=0;
        
        for(int i=0; i<edges.size(); i++){
            vector<int> e = edges[i];
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        
        for(int i=0; i<n; i++){
            if(visited[i]==-1){
                bfs(G, visited, i);
                count++;
            }
        }
        return count;
    }
    void bfs(vector<vector<int>> G, vector<int>& visited, int src) {
        queue<int> Q;
        Q.push(src);
        visited[src] = 1;
        
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            vector<int> adj = G[u];
            for(int j=0; j<adj.size(); j++){
                int v = adj[j];
                if(visited[v] == -1){
                    visited[v] = 1;
                    Q.push(v);
                }
            }
        }
    }
    void dfs(vector<vector<int>> G, vector<int>& visited, int u) {
        visited[u] = 0; //grey
        vector<int> adj = G[u];
        for(int j=0; j<adj.size(); j++){
            int v = adj[j];
            if(visited[v] == -1){
                dfs(G, visited, v);
            }
        }
        visited[u] = 1; //black
    }
};