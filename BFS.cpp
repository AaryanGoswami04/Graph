#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void Createadj(unordered_map<int,vector<int>>& adj, vector<pair<int,int>>& edges){
  for(int i=0; i<edges.size(); i++){
    int u = edges[i].first;
    int v = edges[i].second;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

void printBFS(vector<int>& ans){
  for(auto i:ans)
    cout<<i<<" ";
}

void bfs(unordered_map<int,vector<int>>& adj,unordered_map<int,bool>& visited, vector<int>& ans, int nodeval){
  queue<int>q;
  q.push(nodeval);
  visited[nodeval] = 1;
  
  while(!q.empty()){
    int Front = q.front();
    q.pop();
    ans.push_back(Front);
    
    for(auto i:adj[Front]){
      if(!visited[i]){
          visited[i]=1;
          q.push(i);
        }    
    }   
  }   
}

int main() {
  int n = 5;
  vector<pair<int,int>> edges = {{0,1},{0,3},{2,3},{1,3}};
  vector<int> ans;
  unordered_map<int,bool> visited;
  unordered_map<int,vector<int>> adj;
  
  Createadj(adj, edges);
  
  for(int i=0; i<n; i++){
    if(!visited[i])
        bfs(adj, visited, ans, i);
  }
  printBFS(ans);
}
