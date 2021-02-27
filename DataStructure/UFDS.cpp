class UFDS {

    int n;//number of nodes
    int cnt{};//number of Connected Comps 
    vector <int> par;//parent of node i is par[i]
    vector<int> sz;//size of the component where i belongs == 1 by default
    vector<int> rank;
    public:
        /*Clueless OTZ*/
        UFDS(int _) : n(_) {
            cnt=n;
            par.resize(n+7),sz.resize(n+7),rank.resize(n+1);
            fill(sz.begin(), sz.end(),0);
            iota(par.begin(), par.end(),0);
        }
    
        int Find(int u) {
            return (par[u] == u? u : par[u] = Find(par[u]));//+path compression
        }
    
        bool Connected(int u, int v) {
            return Find(u) == Find(v);//if connected 1,else 0
        }
        
        int Len(int u){
            return sz[Find(u)];
        }

        bool Union(int u, int v) {//merge the set of those 2 nodes
            u = Find(u),v = Find(v);//find root of (_)
            
            if(u==v){return false;}//iz not guranteed that its disjoint
            
            if (rank[u] < rank[v]) swap(u, v);

            par[v] = u;

            if(rank[u] == rank[v]) ++rank[u];
            
            sz[u] += sz[v]; 
            --cnt;//2 comps got merged 
            return 1;
        }
        //Use Len() instead of finding it from the sz vector manually,
        //because only the size of the root of each set is updated.
};
