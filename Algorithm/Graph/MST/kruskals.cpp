

int Kruskal(vector<vector<int>> &Edges, UFDS &ufds) {//Edge[i][0] = weight, [i][1] = u, [i][2] = v
	
	sort(Edges.begin(), Edges.end() /*, greater<int> ()*/);//for the max spanning tree

	int cost{};
	for(auto Edge:Edges) {
		int w = Edge[0], u = Edge[1], v = Edge[2];

		if(ufds.Find(u) == ufds.Find(v)) continue; //to avoid loops

		//cout << u << " --> " << v << '\n'; // prints the mst edges
		cost += w;
		ufds.Union(u,v);
	}

	return cost;
}

/*
5/17//2021 [m/dd/yyyy] 2:41am
*/
