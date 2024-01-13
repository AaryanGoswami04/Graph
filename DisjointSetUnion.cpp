class DisjointSet{
        public:
            vector<int> parent, size;
            DisjointSet(int n){
                parent.resize(n);
                for(int i=0; i<n; i++) parent[i] = i;
                size.resize(n,1);
            }

            int findUltParent(int u){
                if(u == parent[u]) return u;
                return parent[u] = findUltParent(parent[u]);
            }

            void UnionBySize(int u, int v){
                int ultp_u = findUltParent(u);
                int ultp_v = findUltParent(v);

                if(ultp_u == ultp_v) return;

                if(size[ultp_u] < size[ultp_v]){
                    size[ultp_v] += size[ultp_u];
                    parent[ultp_u] = ultp_v;
                }
                else{
                    size[ultp_u] += size[ultp_v];
                    parent[ultp_v] = ultp_u;
                }
            }
    };
