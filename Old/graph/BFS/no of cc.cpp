#include "bits/stdc++.h"
 
using namespace std;

#define all(X)   (X).begin(), (X).end()
#define test     int t;cin>>t;while(t--)
#define len(X)   (int)(X).size()
#define elif     else if
#define bignum   1e9+1
// #define int      long long
#define MAXN     1e3+1

void BFS(int A);

vector<bool> visited(MAXN);//visited array
map<int,vector<int>> AdjList;//adjecency list
int N,E;//no of nodes, no of edges

 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.tie(nullptr);;

    cin>>N>>E;
    for(int i {};i<E;++i) {
        int a,b;cin>>a>>b;a--;b--;
        AdjList[a].push_back(b);
        AdjList[b].push_back(a);
    }
    //IO stuff

    int ConnectedCmp{};
    
    for(int i {};i<N;++i) {
        if(not visited[i]) {
                BFS(i);
                ++ConnectedCmp;
        }
    }

    cout << ConnectedCmp << '\n';
    return 0;
}

void BFS(int A) {

    queue<int> Layer; //to store all the nodes connected to A
    Layer.push(A);
    visited[A] = true; // Node visited.
    
    while(not Layer.empty()) {
        int CurrentNode = Layer.front();

        for(auto Neighbour: AdjList[CurrentNode]) {
            if(visited[Neighbour]) continue;
            if(not visited[Neighbour]) {
                visited[Neighbour] = true;
                Layer.push(Neighbour);
            }
        }

        Layer.pop();
    }

    return ;    
}


//count the number of connected component using bfs
