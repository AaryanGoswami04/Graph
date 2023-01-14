class Solution
{	
public:
  //TC: O(E log E)
  //SC: O(E)
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       int sum = 0;
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
       vector<int> vis(V,0);
       pq.push({0,0});   // {wt, node}
       
       while(!pq.empty()){
           auto it = pq.top();
           pq.pop();
           
           int wt = it.first;
           int node = it.second;
          
           
           if(vis[node])
                continue;
            vis[node]=1;
            sum += wt;
           
           for(auto i:adj[node]){
               int edge_wt = i[1];
               int adjNode = i[0];
               if(!vis[adjNode])
                   pq.push({edge_wt, adjNode});      
           }
       }
       return sum;
    }
};
