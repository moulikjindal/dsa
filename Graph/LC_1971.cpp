class Solution {
public:
    vector<vector<int>> adjacencyList;
    vector<bool> visited;
    bool traverse(int source, int destination, vector<vector<int>>& adjacencyList, int n) {
        // base case
        if (visited[source]) {
            return false;
        }
        if (source == destination) {
            return true;
        }
        visited[source] = true;
        for (int i=0; i < adjacencyList[source].size(); i++) {
            if (!visited[adjacencyList[source][i]]) {
                if (traverse(adjacencyList[source][i], destination, adjacencyList, n)) {
                    return true;
                }
            }
        }
        return false;

    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //graph is bidirectional
        visited.resize(n, false);
        adjacencyList.resize(n);
        for (const auto& edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        return traverse(source, destination, adjacencyList, n);
    }
};