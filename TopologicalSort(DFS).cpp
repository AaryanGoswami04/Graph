//TC:O(V+E)
//SC:O(V)
Class Solution
{
public:
	//Function to return list containing vertices in Topological order. 
	void solve(int node, unordered_map<int,bool>&visited,  vector<int> adj[], stack<int>&s){
        visited[node] = 1;
        
        for(auto neighbour:adj[node]){
            if(!visited[neighbour])
                solve(neighbour, visited, adj, s);
        }
        s.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   unordered_map<int,bool>visited;
	   stack<int>s;
	   
	   for(int i=0; i<V; i++){
	       if(!visited[i])
	            solve(i, visited, adj, s);
	   }
	   
	   vector<int>ans;
	   while(!s.empty()){
	       ans.push_back(s.top());
	       s.pop();
	   }
	   return ans;
	}
};
