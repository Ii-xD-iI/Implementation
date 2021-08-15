class UFDS { //Clueless OTZ
  public:

    int n,cnt{};//number of [nodes, Connected Comps]
    vector <int> par;//par[i] = parent of node i
    vector<int> sz;

    UFDS(int _) : n(_) {            
      cnt=n;//number of cc
      par.resize(n+7), sz.resize(n+7);

      fill(sz.begin(), sz.end(),1);
      iota(par.begin(), par.end(),0);
    }

    int Find(int u) {
      return (par[u] == u? u : par[u] = Find(par[u]));
    }

    bool Connected(int u, int v) {
      return ( Find(u) == Find(v) );          
    } 

    int Len(int u) {
      return sz[Find(u)];
    }

    bool Union(int u, int v) {
      u = Find(u),v = Find(v);
      
      if(u==v) 
        return false;
      
      if (sz[u] < sz[v]) swap(u, v);
      
      par[v] = u;
      sz[u] += sz[v]; 
      --cnt; 
      
      return true;
  }
  /*Use Len() instead of finding it from the sz vector manually,
    because only the size of the root of each set is updated.*/
};
