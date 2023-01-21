class Solution
{
	public:
	void topo(int node, unordered_map<int, bool>& vis, stack<int>& st, vector<int> adj[]){
	   vis[node] = 1;
	   
	   for(auto nbr:adj[node]){
	       if(!vis[nbr])
	        topo(nbr, vis, st, adj);
	   }
	   st.push(node);
	}
	void Revdfs(int node, unordered_map<int, bool>& vis,  unordered_map <int, vector<int>>& rev){
        vis[node]  = 1;
        
        for(auto nbr:rev[node]){
            if(!vis[nbr])
                Revdfs(nbr, vis, rev);
        }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //topo sort
        stack<int> st;
        unordered_map<int, bool> vis;
        for(int i=0; i<V; i++){
            if(!vis[i])
                topo(i, vis, st, adj);
        }
        
        //reverse graph
        unordered_map <int, vector<int>> rev;
        for(int i=0; i<V; i++){
            for(auto& nbr:adj[i])
                rev[nbr].push_back(i);
            vis[i]=0;   //reset visited to 0
        }
        
        //dfs on reversed graph
        int cnt = 0; //ans
        while(!st.empty()){
            int top = st.top();
            st.pop();
            
            if(!vis[top]){
                cnt++;
                Revdfs(top, vis, rev);
            }
        }
        return cnt;
    }
