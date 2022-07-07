
/*
    When graph is dynamically adding edges, we need to maintain to connected component
    as each edge is added.
*/
class Solution {
    vector<int> size;
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n, -1);
        size = vector<int> (n, 1); //size of each set is 1 at init
        int count = n;
        
        for(int i=0; i<n; i++){
            //init parent to self
            parent[i] = i;
        }
        
        for(int i=0; i<edges.size(); i++){
            vector<int> e = edges[i];
            //if union possible then decrease count by 1
            count = count - union_vtx(parent, e[0], e[1]);
        }
        return count;
    }
    int union_vtx(vector<int>& parent, int u, int v){
        int pu = find_parent(parent, u);
        int pv = find_parent(parent, v);
        if(pu == pv) //no union possible if parent are same
            return 0;
        if(size[pu] < size[pv]){
            size[pv] += size[pu];
            parent[pu] = pv;
            
        } else {
            size[pu] += size[pv];
            parent[pv] = pu;
        }
        return 1;
    }
    int find_parent(vector<int>& parent, int u){
        if(parent[u] == u) //reached root of path
            return u;
        
        //update parent of u to achieve path compression
        parent[u] = find_parent(parent, parent[u]);
        return parent[u];
    }
};