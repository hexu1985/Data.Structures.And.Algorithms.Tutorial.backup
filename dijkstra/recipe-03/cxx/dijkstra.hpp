#pragma once

#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <tuple>

template <typename T>
std::set<T> set_difference(const std::set<T>& a, const std::set<T>& b) {    // return a-b
    std::set<T> c = a;
    for (const auto& elem : b) {
        c.erase(elem);
    }
    return c;
}

template <typename Key, typename Value>
std::set<Key> keys(const std::map<Key, Value>& table) {     // get keys set from std::map
    std::set<Key> key_set;
    for (const auto& item: table) {
        key_set.insert(item.first);
    }
    return key_set;
}

template <typename T>
std::vector<T> to_vector(const std::set<T>& a) {        // convert set to vector
    return std::vector<T>(a.begin(), a.end());
}

#define DISTANCE 0 
#define PREVIOUS_NODE 1 

template <typename Vertex>
using Record = std::tuple<double, Vertex>;

template <typename Vertex>
using Table = std::map<Vertex, Record<Vertex>>;

template <typename Graph, typename Vertex>
Table<Vertex> create_shortest_distacne_table(Graph& graph, Vertex origin) {
    Table<Vertex> table;
    for (auto vertex : keys(graph)) {
        if (vertex == origin) {
            table[vertex] = {0, ""};
        } else {
            table[vertex] = {INFINITY, ""};
        }
    }
    return table;
}

template <typename Vertex>
double get_shortest_distance(Table<Vertex>& table, Vertex vertex) {
    auto shortest_distance = std::get<DISTANCE>(table[vertex]);
    return shortest_distance;
}

template <typename Vertex>
void set_shortest_distance(Table<Vertex>& table, Vertex vertex, double new_distance) {
    std::get<DISTANCE>(table[vertex]) = new_distance;
}

template <typename Vertex>
void set_previous_node(Table<Vertex>& table, Vertex vertex, Vertex previous_node) {
    std::get<PREVIOUS_NODE>(table[vertex]) = previous_node;
}

template <typename Graph, typename Vertex>
double get_distance(Graph& graph, Vertex first_vertex, Vertex second_vertex) {
    return graph[first_vertex][second_vertex];
}

template <typename Vertex>
Vertex get_shortest_unincluded_vertex(Table<Vertex>& table, const std::set<Vertex>& included_vertices) {
    auto unincluded_vertices = to_vector(set_difference(keys(table), included_vertices));
    auto assumed_min = std::get<DISTANCE>(table[unincluded_vertices[0]]);
    auto min_vertex = unincluded_vertices[0];
    for (const auto& node : unincluded_vertices) {
        if (std::get<DISTANCE>(table[node]) < assumed_min) {
            assumed_min = std::get<DISTANCE>(table[node]);
            min_vertex = node;
        }
    }
    return min_vertex;
}

template <typename Graph, typename Vertex>
Table<Vertex> find_shortest_path(Graph& graph, Vertex origin) {
    auto table = create_shortest_distacne_table(graph, origin);
    std::set<Vertex> included_vertices;
    while (included_vertices.size() < table.size()) {
        auto current_node = get_shortest_unincluded_vertex(table, included_vertices);
        included_vertices.insert(current_node);
        auto adjacent_nodes = graph[current_node];
        for (auto vertex : set_difference(keys(adjacent_nodes), included_vertices)) {
            auto current_distance = get_shortest_distance(table, vertex);
            auto new_distance = get_shortest_distance(table, current_node) +
                                get_distance(graph, current_node, vertex);
            if (new_distance < current_distance) {
                set_shortest_distance(table, vertex, new_distance);
                set_previous_node(table, vertex, current_node);
            }
        }
    }
    return table;
}
