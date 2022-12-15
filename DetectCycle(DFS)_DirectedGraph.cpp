Class Solution{
  public:
    //TC:O(V+2E)
    //SC:O(2V)
    // Function to detect cycle in a directed graph.
    bool dfs(int node,  vector<int>& visited, vector<int>& DFScalled, vector<int> adj[]){
        visited[node] = 1;
        DFScalled[node] = 1;
        
        for(auto neighbour:adj[node]){
            
            if(!visited[neighbour]){
                bool cycle_present  = dfs(neighbour, visited, DFScalled, adj);
                if(cycle_present)
                    return 1;
            }
            else if(DFScalled[neighbour])
                return true;
        }
      
        DFScalled[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
       //call dfs for all components
       vector<int> visited(V,0);
       vector<int> DFScalled(V,0);

       for(int i=0; i<V; i++){
           if(!visited[i]){
               bool ans = dfs(i, visited, DFScalled, adj);
               if(ans)
                return true;
           }
       }
       return false;
    }
};
