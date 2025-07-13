class Solution {
public:
    vector<int> visited(n, 0);

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //graph is bidirectional
        if (source == destination) return true;
        visited[source] = 1;
        //the validPath function checks if there is a valid path from source to destination in an undirected graph.
        for (int i = 0; i < n; i++) {
            validPath(n, edges, edges[source][i], destination);
        }   
    }
};