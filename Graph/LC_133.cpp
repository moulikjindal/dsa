/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    unordered_map<Node*, Node*> visited; // Map to keep track of visited nodes
    queue<Node*> q; // Queue for BFS traversal
    q.push(node);// Start with the given node
    visited[node] = new Node(node->val);// Create a new node for the cloned graph
    while (!q.empty()) { // While there are nodes to process
        Node* current = q.front();// Get the front node from the queue
        q.pop();// Remove the front node from the queue
        for (Node* neighbor : current->neighbors) { // Iterate through the neighbors of the current node
            if (visited.find(neighbor) == visited.end()) { // If the neighbor has not been visited
                visited[neighbor] = new Node(neighbor->val); // Create a new node for the neighbor
                q.push(neighbor); // Add the neighbor to the queue for further processing
            }
            visited[current]->neighbors.push_back(visited[neighbor]); // 
        }
    }
    return visited[node];

    }
};