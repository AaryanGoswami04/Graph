/*The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.*/
//TC: O(V^3)
//SC: O(V^2)
//If graph has negative cycle, then matrix[i][i]<0 or else matrixt[i][i]=0
void FloydWarshall(vector<vector<int>>&matrix) {
		int n = matrix.size();
	
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++)	matrix[i][j] = min(matrix[i][j],  matrix[i][k] + matrix[k][j]);
			}
		}
}

