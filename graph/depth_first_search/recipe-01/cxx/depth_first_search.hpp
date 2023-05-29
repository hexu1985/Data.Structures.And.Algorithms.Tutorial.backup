#pragma once

#include <vector>
#include <algorithm>

template <typename Graph, typename Vertex>
std::vector<Vertex> depth_first_search(Graph& graph, Vertex root) {
    std::vector<Vertex> visited_vertices{};
    std::vector<Vertex> graph_stack{root};
    auto node = root;

    while (!graph_stack.empty()) {
        node = graph_stack.back(); graph_stack.pop_back();
        if (std::find(visited_vertices.begin(), visited_vertices.end(), node) == visited_vertices.end()) {
            visited_vertices.push_back(node);
            auto adj_nodes = graph[node];
            std::sort(adj_nodes.begin(), adj_nodes.end());
            std::reverse(adj_nodes.begin(), adj_nodes.end());

            for (auto elem : adj_nodes) {
                graph_stack.push_back(elem);
            }
        }
    }

    return visited_vertices;
}
