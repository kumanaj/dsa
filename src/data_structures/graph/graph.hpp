
#include <algorithm>
#include <iostream>
#include <optional>
#include <queue>
#include <stdexcept>
#include <vector>

class Graph {

public:
    Graph(int n) : adj_list(n) { }
    int add_vertex();
    bool remove_vertex(int i);
    void add_edge(int u, int v);
    void remove_edge(int u, int v);
    bool has_edge(int u, int v) ;
    std::vector<int> dfs(int src) const;
    void dfs_helper(int node, std::vector<bool>& visited, std::vector<int>& vertices) const;
    std::vector<int> bfs(int src) const;
    bool is_connected() const;
    bool path_exists(int src, int dest) const;
    std::optional<std::vector<int>> shortest_path(int src, int dst) const;
    int size() const;

private:
    std::vector<std::vector<int>> adj_list;
    void validate_vertex(int i) const;
};

int Graph::add_vertex() {
    adj_list.emplace_back();
    return static_cast<int>(adj_list.size() - 1);
}

bool Graph::remove_vertex(int i) {
    validate_vertex(i);

    // Remove the vertex from the list
    adj_list.erase(adj_list.begin() + i);

    // Update remaining lists
    for (int j = 0; j < adj_list.size(); j++) {
        for (int k = 0; k < adj_list[j].size(); k++) {
            if (adj_list[j][k] == i) {
                adj_list[j].erase(adj_list[j].begin() + k); // Delete links to removed vertex
                k--; // Since we deleted current node, next node is moved to current.
            } else if (adj_list[j][k] > i) { // Decrement index for nodes after i
                    adj_list[j][k]--;
            }
        }
    }
}

// Add a weighted edge from vertex u to vertex v
void Graph::add_edge(int u, int v) {
    validate_vertex(u);
    validate_vertex(v);
    adj_list[u].push_back(v);
}

void Graph::remove_edge(int u, int v) {
    validate_vertex(u);
    validate_vertex(v);
    auto& neighbours = adj_list[u];
    auto it = std::find(neighbours.begin(), neighbours.end(), v);
    if (it != neighbours.end()) {
        neighbours.erase(it);
    }
}

bool Graph::has_edge(int u, int v) {
    validate_vertex(u);
    validate_vertex(v);
    auto& neighbours = adj_list[u];
    auto it = std::find(neighbours.begin(), neighbours.end(), v);
    return it != neighbours.end();
}

std::vector<int> Graph::dfs(int src) const {    
    std::vector<bool> visited(adj_list.size(), false);
    std::vector<int> vertices;
    dfs_helper(src, visited, vertices);
    return vertices;
}

void Graph::dfs_helper(int node, std::vector<bool>& visited, std::vector<int>& vertices) const {
    visited[node] = true;
    vertices.push_back(node);

    for (int neighbour : adj_list[node]) {
        if (!visited[neighbour]) {
            dfs_helper(neighbour, visited, vertices);
        }
    }
}

std::vector<int> Graph::bfs(int src) const {
    std::vector<bool> visited(adj_list.size(), false);
    std::vector<int> vertices;
    std::queue<int> pending_nodes;
    visited[src] = true;
    pending_nodes.push(src);

    while (pending_nodes.size() > 0) {
        int node = pending_nodes.front();
        pending_nodes.pop();        

        for (int neighbour : adj_list[node]) {
            if (!visited[neighbour]) {
                // you want to mark visited soon as possible. otherwise fails in casse like diamond v
                visited[neighbour] = true;
                pending_nodes.push(neighbour);
            }
        }
    }

    return vertices;
}

bool Graph::is_connected() const {
    std::vector<int> visited_vertices = dfs(0);
    return visited_vertices.size() < size();
}

bool Graph::path_exists(int src, int dest) const {
    std::vector<int> visited_vertices = dfs(src);
    auto it = std::find(visited_vertices.begin(), visited_vertices.end(), dest);
    return it != visited_vertices.end();
}

std::optional<std::vector<int>> Graph::shortest_path(int src, int dst) const {

}

int Graph::size() const {
    return adj_list.size();
}

void Graph::validate_vertex(int i) const {
    if (i < 0 || i >= adj_list.size()) throw std::out_of_range("invalid index");
}
