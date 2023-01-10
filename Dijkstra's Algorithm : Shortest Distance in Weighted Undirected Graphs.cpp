class Solution
{
public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V,INT_MAX);
        dist[S]=0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> MinHeap;
        MinHeap.push({0,S});
        
        while(!MinHeap.empty()){
            int top_dist =  MinHeap.top().first;
            int top_node =  MinHeap.top().second;
            MinHeap.pop();
            
            for(auto i:adj[top_node]){
                int Edge_Weight = i[1];
                int neighbour = i[0];
                
                if(top_dist+ Edge_Weight < dist[neighbour]){
                    dist[neighbour] = top_dist + Edge_Weight;
                    MinHeap.push({dist[neighbour],neighbour});
                }
            }
        }
        return dist;
    }
};
