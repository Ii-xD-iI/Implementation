using namespace std;
#include "bits/stdc++.h"

bool CycleDetection(int Node, int Parent);

bool Cycle = false;
int Nodes,Edges;
vector<vector<int>> Adj(Nodes+7);//Adj_List
vector<int> Visited(Nodes +7);

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    cin>>Nodes>>Edges;
    for(int i {};i<Edges; ++i) {
        int U,V;
        cin>>U>>V;
        // U --> V 
        Adj[U].emplace_back(V);
        // Adj[V].emplace_back(U);
    }

    
    for(int i=1;i<=Nodes;++i) {
        if( (not Visited[i]) and CycleDetection(i, -1) ) {//curr Node, Parent
            Cycle= true;
        }
    }

    cout << (Cycle? "Cycle Detected\n": "No Cycle was found\n");
    return 0;

}

bool CycleDetection(int Node, int Parent) {
    Visited[Node] = true;

    for(auto &Child: Adj[Node]) {
        if(Child == Parent) continue;

        if(Visited[Child]) 
            return true;
        
        else if( ( not Visited[Child]) and CycleDetection(Child, Node)) {
            return true;
        }
    }

    return false;
}
/*
5/11/2021 m/dd/yyyy
*/
