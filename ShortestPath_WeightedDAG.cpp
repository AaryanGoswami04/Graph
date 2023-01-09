#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Graph {
public:
  void createAdj(int u, int v, int weight,
                 unordered_map<int,vector<pair<int, int>>> &Adj) {
    Adj[u].push_back({v, weight});
  }
};

void dfs(int node, unordered_map<int,vector<pair<int, int>>> Adj, vector<int> &vis,stack<int> &s) {
  vis[node] = 1;
  for (auto it : Adj[node]) {
    if (!vis[it.first])
      dfs(it.first, Adj, vis, s);
  }
  s.push(node);
}

void ShortestDistance(int src,vector<int>& dist,stack<int>& s, unordered_map<int,vector<pair<int, int>>>Adj){
  while(!s.empty()){
    int top = s.top();
    s.pop();

    if(dist[top] != INT_MAX){
      for(auto i:Adj[top]){
        if(dist[top] + i.second < dist[i.first])
            dist[i.first] = dist[top] + i.second;
      }
    }
  }
}
int main() {
  Graph g;
  int n = 9; //no. of edges
  unordered_map<int,vector<pair<int, int>>> Adj;

  for (int i = 0; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g.createAdj(u, v, w, Adj);
  }
  
  //Topological Sort
  vector<int> vis(6);
  stack<int> s;
  for (int i = 0; i < 6; i++) {
    if (!vis[i])
      dfs(i, Adj, vis, s);
  }
  
  vector<int> dist(6,INT_MAX);
  int start = 1;
  dist[start]=0;
  ShortestDistance(1,dist,s,Adj);
  
  cout<<"Printing ans:"<<endl;
  for(auto i:dist)
      cout<<i<<endl;
  
}
