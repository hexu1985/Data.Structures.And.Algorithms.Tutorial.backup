#include "dijkstra.hpp"
#include "tuple_printer.hpp"

#include <string>
#include <cmath>
#include <tuple>
#include <iostream>

using Vertex = std::string;
using Graph = std::map<Vertex, std::map<Vertex, double>>;

void test() {
    Graph graph;
    graph["s"] = {{"v", 1}, {"w", 4}};
    graph["v"] = {{"w", 2}, {"t", 6}};
    graph["w"] = {{"t", 3}};
    graph["t"] = {};

    auto shortest_distance_table = find_shortest_path(graph, Vertex{"s"});

    for (auto k : keys(shortest_distance_table)) {
        std::cout << k << " - " << shortest_distance_table[k] << "\n";
    }
}

int main() {
    test();
}
