class Solution
{
public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>indegree(V,0);
	    for(int i=0; i<V; i++){
	        for(auto it:adj[i])
	           indegree[it]++;
	    }
	    
	    queue<int>q;
	    for(int i=0; i<V; i++){
	        if(!indegree[i])
	            q.push(i);
	    }
	        
	    vector<int>topo;
	    while(!q.empty()){
	        int front = q.front();
	        q.pop();
	        topo.push_back(front);
	        
	        for(auto i:adj[front]){
	            indegree[i]--;
	            if(!indegree[i])
	                q.push(i);
	        }
	        
	    }
	    return topo;
	}
};
