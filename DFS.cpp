//TC: O(V+E)
void dfs(int node,unordered_map<int,vector<int>>& adj , vector<int>& visited, vector<int>& component){
      visited[node]=1;
      component.push_back(node);
      
      for(auto i:adj[node]){
          if(!visited[i])
            dfs(i, adj, visited, component);
      }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    //create adj list;
    unordered_map<int,vector<int>> adj;
    for(int i=0; i<E; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>>ans;
    vector<int>visited(V,0);
  
    for(int i=0; i<V; i++){ //Traverse all nodes to handle the case of disconnected graph
        if(!visited[i]){
            vector<int> component;
            dfs(i, adj, visited, component);
            ans.push_back(component);
        }
    }
    return ans;
}
