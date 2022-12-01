#pragma once

#include <vector>
#include <deque>
#include <algorithm>

template <typename Graph, typename Vertex>
std::vector<Vertex> breadth_first_search(Graph& graph, Vertex root) {
    std::vector<Vertex> visited_vertices{root};
    std::deque<Vertex> graph_queue{root};
    auto node = root;

    while (!graph_queue.empty()) {
        node = graph_queue.front(); graph_queue.pop_front();
        auto adj_nodes = graph[node];
        std::sort(adj_nodes.begin(), adj_nodes.end());

        for (auto elem : adj_nodes) {
            if (std::find(visited_vertices.begin(), visited_vertices.end(), elem) != visited_vertices.end()) {
                continue;
            }
            visited_vertices.push_back(elem);
            graph_queue.push_back(elem);
        }
    }

    return visited_vertices;
}
