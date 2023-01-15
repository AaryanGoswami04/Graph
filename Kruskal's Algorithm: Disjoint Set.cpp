/*Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.*/
//TC: O(E log E)
//SC: O(2V)
class DisjointSet{
    vector<int> rank, parent;
    public:
        DisjointSet(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            for(int i=0; i<n; i++){
                parent[i] = i;
            }
        }
  
        int findUPar(int node){   //to find ultimate parent
            if(node == parent[node])
                return node;
            return parent[node] = findUPar(parent[node]);
        }
  
        void UnionbyRank(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            
            if(rank[ulp_u] < rank[ulp_v])
                parent[ulp_u] = ulp_v;
                
            else if (rank[ulp_v] < rank[ulp_u])
                parent[ulp_v] = ulp_u;
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       vector<pair<int, pair<int,int>>> edges;
       for(int i=0; i<V; i++){
           for(auto it:adj[i]){
               int adjNode = it[0];
               int wt = it[1];
               int node = i;
               
               edges.push_back({wt, {node, adjNode}});
           }
       }
       
       DisjointSet ds(V);
       sort(edges.begin(), edges.end());
       int ans = 0;
       
       for(auto it:edges){
           int wt = it.first;
           int u = it.second.first;
           int v = it.second.second;
           
           if(ds.findUPar(u) != ds.findUPar(v)){
               ans += wt;
               ds.UnionbyRank(u,v);
           }
       }
       return ans;
    }
};
