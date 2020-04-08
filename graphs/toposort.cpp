//Print all possible toposort
// DFS based and using backtracking

class Graph {
    int V;
    list<int> *adj;
    vector<int> indegree;
public:
    Graph(int vertex);  //constructor...no return type
    void addedge(int src, int dest);
    void all_topo_sort(vector<int> &result, vector<bool> &visited)
};

Graph::Graph(int vertex) {
    V = vertex;
    adj = new list<int>[V];
    indegree = vector<int>(V, 0);
} 
void Graph::addEdge(int src, int dst) 
{ 
    adj[src].push_back(dst);
    indegree[dst]++; 
}
void Graph::all_topo_sort(vector<int> &result, vector<bool> &visited) {
    bool flag = false;
    for(int i=0; i<V; i++){
        if(indegree[i]==0 && !visited[i]){
            for(auto it=adj[i].begin(); it != adj[i].end(); it++) {
                indegree[*it]--;
            }
            visited[i] = true;
            result.push_back(i);
            all_topo_sort(result, visited);
            
            //Backtrack
            result.pop_back();
            visited[i]=false;
            for(auto it=adj[i].begin(); it != adj[i].end(); it++){
                indegree[*it]++;
            }
            flag = true;
        }
    }
    if(!flag){
        //all vertices are visited...print the result
        for(int j=0; j<result.size(); j++){
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    //create GRAPH
    vector<int> result;
    vector<bool> visited(num_vertex, false);
    all_topo_sort(result, visited);
}


/////         SINGLE TOPOSORT...any one of all possible toposort  using queue
////   DETECT CYCLE
void toposort(Graph *G){ 
    vector<int> in_degree(V, 0); 
  
    for (int u=0; u<V; u++)  { 
        for (auto itr = adj[u].begin(); itr != adj[u].end(); itr++) 
             in_degree[*itr]++; 
    }
    queue<int> q; 
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) 
            q.push(i); 
    }
    // Initialize count of visited vertices 
    int cnt = 0; 
    vector <int> topo_order; 
    while (!q.empty()) {
        int u = q.front(); 
        q.pop();
        topo_order.push_back(u); 
        for (auto itr = adj[u].begin(); itr != adj[u].end(); itr++) {
            if (--in_degree[*itr] == 0) 
                q.push(*itr); 
        }
        cnt++; 
    }
    // Check if there was a cycle 
    if (cnt != V) {
        cout << "There exists a cycle in the graph\n"; 
        return; 
    } 
    // Print topological order 
    for (int i=0; i<topo_order.size(); i++) 
        cout << topo_order[i] << " "; 
    cout << endl;
}