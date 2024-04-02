vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>>& edges) {
    vector<int> graph[n];

	// Creating the graph.
	for(int i = 0; i < edges.size(); i++){

		// Adding adjecent nodes.
		graph[edges[i][0]].push_back(edges[i][1]);
		graph[edges[i][1]].push_back(edges[i][0]);
	}

	// Create an adjacency list of size 'N'.
	vector<vector<int>> adjacencyList(n);

	for(int i = 0; i < n; i++) {
		adjacencyList[i].push_back(i);

		for(int j = 0; j < graph[i].size(); j++) {
			adjacencyList[i].push_back(graph[i][j]);
		}
	}

	return adjacencyList;
}
