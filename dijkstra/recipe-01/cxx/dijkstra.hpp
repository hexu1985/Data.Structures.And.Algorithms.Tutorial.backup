#pragma once

#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <tuple>
#include <type_traits>

#define DISTANCE 0 
#define PREVIOUS 1 

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

template <typename Table, typename Vertex>
double get_distance(Table& table, Vertex vertex) {
    return std::get<DISTANCE>(table[vertex]);
}

template <typename Table, typename Vertex>
void set_distance(Table& table, Vertex vertex, double distance) {
    std::get<DISTANCE>(table[vertex]) = distance;
}

template <typename Table, typename Vertex>
void set_previous(Table& table, Vertex vertex, Vertex previous) {
    std::get<PREVIOUS>(table[vertex]) = previous;
}

template <typename Graph, typename Vertex>
double edge_length(Graph& graph, Vertex from, Vertex to) {
    return graph[from][to];
}

template <typename Table, typename Vertex>
Vertex get_shortest_unincluded_vertex(Table& table, const std::set<Vertex>& included_vertices) {
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

template <typename Table, typename Vertex>
void initialize_distance_table(Table& table, Vertex origin) {
    // check distance type is floating point
    using RecordType = typename std::decay<decltype(table[origin])>::type;
    using DistanceType = typename std::tuple_element<DISTANCE, RecordType>::type;
    static_assert(std::is_floating_point<DistanceType>::value, "distance type must be floating point");

    for (const auto& vertex : keys(table)) {
        if (vertex == origin) {
            table[vertex] = {0, {}};
        } else {
            table[vertex] = {INFINITY, {}};
        }
    }
}

template <typename Graph, typename Table, typename Vertex>
Table& find_shortest_path(Graph& graph, Table& table, Vertex origin) {
    initialize_distance_table(table, origin);
    std::set<Vertex> included_vertices = {};
    while (included_vertices.size() < table.size()) {
        auto current_node = get_shortest_unincluded_vertex(table, included_vertices);
        included_vertices.insert(current_node);
        auto adjacent_nodes = graph[current_node];
        for (auto vertex : set_difference(keys(adjacent_nodes), included_vertices)) {
            auto current_distance = get_distance(table, vertex);
            auto new_distance = get_distance(table, current_node) + edge_length(graph, current_node, vertex);
            if (new_distance < current_distance) {
                set_distance(table, vertex, new_distance);
                set_previous(table, vertex, current_node);
            }
        }
    }
    return table;
}
