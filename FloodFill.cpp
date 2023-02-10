class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        int m = image.size(); //no. of rows
        int n = image[0].size(); //no. of col
        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<int,int>> q;
        image[sr][sc] = color;
        q.push({sr,sc});
        
      //bfs
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            int delrow[] = {-1,0,0,1};
            int delcol[] = {0,-1,1,0};

            for(int i=0; i<4; i++){
                int newr = delrow[i] + r;
                int newc = delcol[i] + c;

                if(newr >=0 and newr < m and newc >= 0 and newc < n and image[newr][newc] == iniColor and !vis[newr][newc]){
                    vis[newr][newc] = 1;
                    image[newr][newc] = color;
                    q.push({newr,newc});
                }
            }
        }
        return image;
    }
};
