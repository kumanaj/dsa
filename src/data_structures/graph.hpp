#pragma once

#include <algorithm>
#include <optional>
#include <queue>
#include <stdexcept>
#include <vector>

class Graph {

public:
    explicit Graph(int n) : adj_list(n) { }

    int add_vertex() {
        adj_list.emplace_back();
        return static_cast<int>(adj_list.size() - 1);
    }

    bool remove_vertex(int i) {
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
        return true;
    }

    // Add a directed edge from vertex u to vertex v
    void add_edge(int u, int v) {
        validate_vertex(u);
        validate_vertex(v);
        adj_list[u].push_back(v);
    }

    void remove_edge(int u, int v) {
        validate_vertex(u);
        validate_vertex(v);
        auto& neighbours = adj_list[u];
        auto it = std::find(neighbours.begin(), neighbours.end(), v);
        if (it != neighbours.end()) {
            neighbours.erase(it);
        }
    }

    bool has_edge(int u, int v) const {
        validate_vertex(u);
        validate_vertex(v);
        auto& neighbours = adj_list[u];
        auto it = std::find(neighbours.begin(), neighbours.end(), v);
        return it != neighbours.end();
    }

    std::vector<int> dfs(int src) const {
        validate_vertex(src);
        std::vector<bool> visited(adj_list.size(), false);
        std::vector<int> vertices;
        dfs_helper(src, visited, vertices);
        return vertices;
    }

    std::vector<int> bfs(int src) const {
        validate_vertex(src);
        std::vector<bool> visited(adj_list.size(), false);
        std::vector<int> vertices;
        std::queue<int> pending_nodes;
        visited[src] = true;
        pending_nodes.push(src);

        while (pending_nodes.size() > 0) {
            int node = pending_nodes.front();
            pending_nodes.pop();
            vertices.push_back(node);

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

    bool is_connected() const {
        // Directed graph: "connected" here means every vertex is reachable from vertex 0.
        if (adj_list.empty()) return true;
        std::vector<int> visited_vertices = dfs(0);
        return static_cast<int>(visited_vertices.size()) == size();
    }

    bool path_exists(int src, int dest) const {
        validate_vertex(dest);   // dfs() validates src
        std::vector<int> visited_vertices = dfs(src);
        auto it = std::find(visited_vertices.begin(), visited_vertices.end(), dest);
        return it != visited_vertices.end();
    }

    // TODO: not implemented yet
    std::optional<std::vector<int>> shortest_path(int src, int dst) const {
        throw std::logic_error("Graph::shortest_path not implemented");
    }

    int size() const {
        return static_cast<int>(adj_list.size());
    }

private:
    std::vector<std::vector<int>> adj_list;

    void dfs_helper(int node, std::vector<bool>& visited, std::vector<int>& vertices) const {
        visited[node] = true;
        vertices.push_back(node);

        for (int neighbour : adj_list[node]) {
            if (!visited[neighbour]) {
                dfs_helper(neighbour, visited, vertices);
            }
        }
    }

    void validate_vertex(int i) const {
        if (i < 0 || i >= size()) throw std::out_of_range("invalid index");
    }
};
