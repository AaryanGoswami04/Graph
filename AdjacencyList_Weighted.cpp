#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
  int n = 5;
  vector<pair<int,int>> edges = {{0,1},{0,3},{2,3},{1,3}};
  vector<int>weights{3,2,8,6}; //weight[i] is the weight of edges[i]
  vector<pair<int,int>> adj[n];
  
  for(int i=0; i<edges.size(); i++){  //creating an adjacency list
    int u = edges[i].first;
    int v = edges[i].second;
    adj[u].push_back({v,weights[i]});
    adj[v].push_back({u,weights[i]});
  }
 
  for(int i=0; i<n; i++){     //printing adjacency list
       cout<<i<<"->";
      for(auto j:adj[i])
        cout<<"{"<<j.first<<","<<j.second<<"} ";
      cout<<endl;
    }
 
}
/* Output:
0->{1,3} {3,2} 
1->{0,3} {3,6} 
2->{3,8} 
3->{0,2} {2,8} {1,6} 
4->
*/
