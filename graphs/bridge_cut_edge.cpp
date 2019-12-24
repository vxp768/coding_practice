class Solution {
    int dfs_counter=0;
    vector<vector<int>> edges;
    vector<int> parent; 
    vector<int> children;
    vector<int> dfs;
    vector<int> low;
    vector<int> color;
    vector<vector<int>> bridges;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        if(n<=0 || connections.size()<=0 || connections[0].size()<=0)
            return bridges;
        edges = vector<vector<int>> (n, vector<int>{});
        parent = vector<int> (n, -1);
        children = vector<int> (n, 0);
        dfs   = vector<int> (n, -1); 
        low   = vector<int> (n, -1);
        color = vector<int> (n, -1); //WHITE
        //process connections and get edges
        for(int i=0; i<connections.size(); i++){
            vector<int> e = connections[i];
            edges[e[0]].push_back(e[1]);
            edges[e[1]].push_back(e[0]);
        }
        for(int u=0; u<n; u++){
            if(color[u]==-1){
                DFS(u); //DFS tree rooted at i
            }
        }
        return bridges;
    }
    void DFS(int u){
        color[u] = 1; //GREY
        low[u] = dfs[u] = ++dfs_counter;
        for(int i=0; i<edges[u].size(); i++){
            int v = edges[u][i];
            if(color[v] == -1) { //WHITE
                children[u]++;
                parent[v] = u;
                DFS(v);
                //update lowest reachable vertex from u
                low[u] = min(low[u], low[v]);
                if (low[v] > dfs[u]){
                    bridges.push_back({u,v});   
                }
            } else if(parent[u] != v) {
                //back edge from u to v
                low[u] = min(low[u], dfs[v]);
            }
        }
        color[u] = 2; //BLACK;
    }
};