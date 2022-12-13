Class Solution{
public:
    // Function to detect cycle in an undirected graph.
    bool iscyclicBFS(int start, vector<int>& visited, unordered_map<int,int>& parent,vector<int> adj[]){
            parent[start] = -1; //Starting node has no parent
            visited[start] = 1;
            queue<int>q;
            q.push(start);
            
            while(!q.empty()){
                int front=q.front();
                q.pop();
                
               for(auto i:adj[front]){ //i is the neighbour of front
                   if(visited[i] && i != parent[front])
                       return true;
                   
                   else if(!visited[i]){
                       q.push(i);
                       visited[i]=1;
                       parent[i]=front;
                   }  
               }
            }
            return false;
    }
    bool isCycle(int V,vector<int> adj[]) {
        unordered_map<int,int>parent; //Maps node to its parent
        vector<int>visited(V,0);
        
        for(int i=0; i<V; i++){   //To handle disconnected components
            if(!visited[i]){
                bool ans = iscyclicBFS(i, visited, parent, adj);
                if(ans)
                    return 1;
            }
        }
        return 0;
    }
};
