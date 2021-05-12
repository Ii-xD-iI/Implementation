using namespace std;
#include "bits/stdc++.h"
bool CycleDFS(int &Node);

int Nodes,Edges;
bool CycleDetected = false;
vector<vector<int>> Adj(1e5+7);
vector<int> Stack(1e5+7);
vector<bool> Visited(1e5+7);

signed main() {

    cin>>Nodes>>Edges;

    for(int U,V,i=1;i<=Edges;++i) {
        cin>>U>>V;
        Adj[U].push_back(V);
    }

    for(int i=0;i<=Nodes; ++i) {
        if(not Visited[i] and CycleDFS(i)) {CycleDetected = true;break;}
    }

    cout << (CycleDetected? "Cycle Found\n":"No Cycle Detected\n");
    return 0;
}

bool CycleDFS(int &Node) {
    Stack[Node] = true;
    if(not Visited[Node]) {
        Visited[Node] = true;
        for(auto Child: Adj[Node]) {
            if( (not Visited[Child]) and CycleDFS(Child)) return true;//not visited but is in the stack
            if(Stack[Child]) return true;//if a child is already in the stack
        }
    }
    Stack[Node] = false;
    return false;
}
/*
5/12/2021 m/dd/yyyy
*/
