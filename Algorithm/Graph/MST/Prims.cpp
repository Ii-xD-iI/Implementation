using namespace std;

const int N = 1e5+7, INF = 2e9+7;
vector<int> Distance(N,INF), Parent(N);
vector<vector<vector<int>>> Adj(N);
vector<bool> Visited(N);

int Prims(int Node) { int Cost{};

	set<vector<int>> s;
	Distance[Node] = 0;
	s.insert({0,Node});//cost, end

	while(not s.empty()) {
		vector<int> Curr = *s.begin();
		s.erase(Curr);

		Visited[Curr[1]] = true;//weight,vertex

		int U = Curr[1];//V-->U
		int V = Parent[Curr[1]];
		int Weight = Curr[0];

		// cout << U << "-->" << V << " = " << Weight << '\n';
		Cost += Weight;

		for(auto i: Adj[Curr[1]]) {
			if(Visited[i[0]]) continue;

			if(Distance[i[0]] > i[1]) {
				s.erase({Distance[i[0]], i[0]});

				Distance[i[0]] = i[1];

				s.insert({Distance[i[0]], i[0]});
				Parent[i[0]] = Curr[1];
			}
		}
	}
	return Cost;
}
/*
5/17/2021 [m/dd/yyyy] 4:31pm
*/
