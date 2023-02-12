//Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).
class Solution {
  public:
  //TC: O(n*m*log(n*m) + n*m)
  //SC: O(n*m)
   void dfs(int r, int c,vector<vector<int>>& vis, vector<vector<int>>& grid, vector<pair<int,int>>& vec, int r0, int c0, int n,int m){
       vis[r][c] = 1;
       vec.push_back({r-r0, c-c0});   // r0 - row of ref. cell ; c0 - col of ref. cell
       
       
       int delrow[] = {-1,0,1,0};
       int delcol[] = {0,-1,0,1};
     
       for(int i=0; i<4; i++){
           int nrow = r + delrow[i];
           int ncol = c + delcol[i];
           if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and grid[nrow][ncol] == 1)
                dfs(nrow, ncol, vis, grid,vec, r0, c0, n, m);        
       }
   } 
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] and grid[i][j] == 1){
                    vector<pair<int,int>> vec;  //stores list of pairs of differences between coordinates of Reference cell, current cell
                    dfs(i, j, vis, grid, vec, i, j,n,m);
                    st.insert(vec);  //stores unqiue islands
                }
            }
        }
        return st.size();
    }
};
