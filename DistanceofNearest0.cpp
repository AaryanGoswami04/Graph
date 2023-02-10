//Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell. The distance between two adjacent cells is 1.
class Solution {
public:
    //TC: O(M*N)
    //SC: O(M*N)

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m,0));
        vector<vector<int>> vis(n, vector<int>(m,0));

        queue<pair<pair<int,int>, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});    // {{r,c},dist}
                    vis[i][j] = 1;
                }
            }
        }

        //bfs
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;

            dist[r][c] = d;
            q.pop();

            int delrow[] = {-1,0,0,1};
            int delcol[] = {0,-1,1,0};

            for(int i=0; i<4; i++){
                int newr = delrow[i] + r;
                int newc = delcol[i] + c;
                if(newr >=0 and newr < n and newc >= 0 and newc < m and vis[newr][newc] == 0){
                    vis[newr][newc] = 1;
                    q.push({{newr, newc}, d+1});
                } 
            }
        }
        return dist;
    }
};
