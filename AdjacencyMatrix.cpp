#include <iostream>
using namespace std;
//SC: O(N*N)
int main() {
  //n: no. of vertices
  //m: number of edges
  int n,m;
  cin>>n>>m;
  int adj[n+1][n+1];
  for(int i=0; i<m; i++){
    int u,v;
    cin>>u>>v;
    adj[u][v]=1;
    adj[v][u]=1;
  }
}
