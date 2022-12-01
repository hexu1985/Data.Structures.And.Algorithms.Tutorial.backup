#pragma once

#include <vector>
#include <algorithm>

template <typename Graph, typename Vertex>
void depth_first_search(Graph& graph, Vertex node, std::vector<Vertex>& visited_vertices) {
    if (std::find(visited_vertices.begin(), visited_vertices.end(), node) == visited_vertices.end()) {
        visited_vertices.push_back(node);
    }

    auto adj_nodes = graph[node];
    std::sort(adj_nodes.begin(), adj_nodes.end());
    for (auto elem : adj_nodes) {
        if (std::find(visited_vertices.begin(), visited_vertices.end(), elem) == visited_vertices.end()) {
            depth_first_search(graph, elem, visited_vertices);
        }
    }
}

template <typename Graph, typename Vertex>
std::vector<Vertex> depth_first_search(Graph& graph, Vertex root) {
    std::vector<Vertex> visited_vertices{};
    depth_first_search(graph, root, visited_vertices);
    return visited_vertices;
}
