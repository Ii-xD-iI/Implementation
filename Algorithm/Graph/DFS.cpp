void DFS(int Node) {
	visited[Node] = true;




	for(auto Neighbour: adj[Node]){
		if(not visited[Neighbour])

			DFS(Neighbour);
	}
}
