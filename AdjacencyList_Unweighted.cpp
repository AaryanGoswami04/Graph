#include <iostream>
#include<vector>
using namespace std;
//Below code is for unweighted graph
//Directed graph: SC:O(E)
//Undirected graph: SC:O(2E)
int main() {
  //n: no. of vertices
  //m: number of edges
  int n,m;
  cin>>n>>m;
  
  cout<<"Enter if graph is directed or not"<<endl;
  int direction;
  cin>>direction;
  
  vector<int>adj[n+1]; //1 based indexing
  for(int i=0; i<m; i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    if(direction==0)    //undirected graph
      adj[v].push_back(u);
  }
}
