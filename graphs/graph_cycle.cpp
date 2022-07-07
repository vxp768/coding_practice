/////// UNDIRECTED GRAPH
//// "backedge" concept applies only to directed graph

#include<bits/stdc++.h>
using namespace std;
class Graph {
    
    public:
    int V;
    vector<int> *adj;
    
    Graph(int n){
        V = n;
        adj = new vector<int>[n];
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};
bool dfs(int u, vector<int>& visited, Graph &G, int parent) {
    visited[u] = 1;
    vector<int> adju = G.adj[u];
    
    for(int i=0; i<adju.size(); i++){
        if(visited[adju[i]] == 0){
            if (dfs(adju[i], visited, G, u)){
                return true;
            }
        } else {
            if(adju[i] != parent){
                return true;
            }
        }
    }
    return false;
}
bool contains_cycle(int n, vector<pair<int,int> > edges){
    //Complete this method
    Graph G(n);
    vector<int> visited(n, 0);
    
    for(int i=0; i<edges.size(); i++){
        pair<int,int> p = edges[i];
        G.addEdge(p.first, p.second);    
    }
    for(int i=0; i<n; i++){
        if (visited[i] == 0){
            if (dfs(i, visited, G, -1) == true){
                return true;
            } 
        }
    }
    return false;
}




/////     DIRECTED GRAPH
////   IF BACKEDGE exists then there is cycle
#include<bits/stdc++.h>
using namespace std;

class Graph {
  
  public:
  int V;
  vector<int> *adj;
  Graph(int n){
      V = n;
      adj = new vector<int>[n];
  }
  void addEdge(int u, int v){
      adj[u].push_back(v); //directed graph
  }
};

bool dfs(int u, Graph G, vector<int> &visited, vector<int> &rec_stack){
    visited[u] = 1;
    rec_stack[u] = 1;
    
    vector<int> adju = G.adj[u];
    for(int i=0; i<adju.size(); i++){
        int v = adju[i];
        if (visited[v]==0){
            if (dfs(v, G, visited, rec_stack) == true){
                return true;
            }
        } else {
            if(rec_stack[v]==1){
                //// If vertex v is in current stack then there is back edge
                return true;
            }
        }
    }
    rec_stack[u] = 0; /// remove the vertex from recursive stack as the vertex is completely processed
    return false;
}

bool contains_cycle(int n,vector<pair<int,int> > edges){
    //Complete this method
    Graph G(n);
    vector<int> visited(n, 0);
    vector<int> rec_stack(n, 0);
    
    for(int i=0; i<edges.size(); i++){
        pair<int, int> p = edges[i];
        G.addEdge(p.first, p.second);
    }
    return dfs(0, G, visited, rec_stack);
}