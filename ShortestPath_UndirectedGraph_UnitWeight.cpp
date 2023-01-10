/*You are given an Undirected Graph having unit weight, Find the shortest path from src(0) to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.*/
class Solution
{
public:
    void createAdj(vector<vector<int>>& edges, vector<int> Adj[]){
        for(auto itr:edges){
            int u = itr[0];
            int v = itr[1];
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }
    }
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> Adj[N];
        createAdj(edges, Adj);
       
       int dist[N]; //stores disatnce of each node from 0
       for(int i=0; i<N; i++)
           dist[i]=1e9;
      
       dist[src]=0;
       queue<int>q;
       q.push(src);
       
       while(!q.empty()){
           int front = q.front();
           q.pop();
           
           for(auto it:Adj[front]){
               if(dist[front]+1 < dist[it]){
                   dist[it]=dist[front]+1;
                   q.push(it);
               }
           }
       }
       vector<int> ans(N,-1);
       for(int i=0; i<N; i++){
           if(dist[i] != 1e9)
            ans[i]=dist[i];
       }
       return ans;
    }
};
