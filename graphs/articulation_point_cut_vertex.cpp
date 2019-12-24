



class Solution {
    int dfs_counter=0;
    vector<vector<int>> edges;
    vector<int> parent; 
    vector<int> children;
    vector<int> dfs;
    vector<int> low;
    vector<int> color;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> AP;
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
                //if root node has more than 1 child then its AP
                if(children[u] > 1){
                    //Articulation point
                    AP.push_back(u);   
                }
            }
        }
        return AP;
    }
    void DFS(int u){
        color[u] = 1; //GREY
        low[u] = dfs[u] = ++dfs_counter;
        for(int i=0; i<edges[u].size(); i++){
            int v = edges[u][i];
            if(color[v] == -1) { //WHITE
                children[v]++;
                parent[v] = u;
                DFS(v);
                //update lowest reachable vertex from u
                low[u] = min(low[u], low[v]);
                if (parent[u] != -1 && low[v] >= dfs[u]){
                    //u is articulation point
                    AP.push_back(u);   
                }
            } else if(parent[u] != v) {
                //back edge from u to v
                low[u] = min(low[u], dfs[v]); 
            }
        }
        color[u] = 2; //BLACK;
    }
};