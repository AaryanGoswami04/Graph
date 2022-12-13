class Solution{
  public:
    // Function to detect cycle in an undirected graph.
    bool DFS(int node, int parent, vector<int>& visited,vector<int>adj[]){
        visited[node] = 1;
        
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                bool cycle_detected = DFS(neighbour, node, visited, adj);
                if(cycle_detected)
                    return true;
            }
            
            else if(neighbour != parent)
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>visited(V,0);
      
        for(int i=0; i<V; i++){
            if(!visited[i]){
                bool ans = DFS(i,-1,visited,adj);
                if(ans)
                    return 1;
          }
      }
      return 0;
    }
};
