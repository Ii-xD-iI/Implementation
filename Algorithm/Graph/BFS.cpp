void BFS(int S,int N, vector<bool> visited,vector<vector<int>> AdjList){
		//:Source, Number of nodes, AdjList

    queue<int> Layer; //to store all the nodes connected to the source
    Layer.push(S);
    
    visited[S] = true; // Node visited.
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
    return;    
}
