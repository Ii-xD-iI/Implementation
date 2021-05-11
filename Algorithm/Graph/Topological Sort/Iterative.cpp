using namespace std;
#include "bits/stdc++.h"

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    int Nodes,Edges;
    cin>>Nodes>>Edges;
    vector<vector<int>> Adj(Nodes+7);//Adj_List
    vector<int> InDegree(Nodes+7);//number of edges pointing at the node i
    for(int i {};i<Edges; ++i) {
        int U,V;
        cin>>U>>V;
        // U --> V 
        Adj[U].emplace_back(V);
        InDegree[V]++;
    }
    // for(int i{};i<=Nodes; ++i) cout << InDegree[i] << " \n"[i == Nodes];
    queue<int> Layer;
    for(int i=1;i<=Nodes;++i) {
        if(not InDegree[i]) Layer.push(i);
    }
    vector<int> TopologicalSort;
    while(not Layer.empty()) {
        int curr = Layer.front();

        TopologicalSort.push_back(curr);
        
        for(auto Neighbour: Adj[curr]) {
            --InDegree[Neighbour];
            if(not InDegree[Neighbour]) Layer.push(Neighbour);
        }
        
        Layer.pop();
    }
    if ((TopologicalSort).size() < Nodes) {
        cout << "Cycle Detected\n";
        return 0;
    }
    for(auto i :TopologicalSort) cout << i << ' ';
    cout << '\n';

    return 0;









}
