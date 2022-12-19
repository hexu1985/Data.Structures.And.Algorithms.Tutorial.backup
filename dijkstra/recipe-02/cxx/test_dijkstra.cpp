#include "dijkstra.hpp"
#include "tuple_printer.hpp"

#include <string>
#include <cmath>
#include <tuple>
#include <iostream>

using Vertex = std::string;
using Graph = std::map<Vertex, std::map<Vertex, double>>;
using Record = std::tuple<double, Vertex>;
using Table = std::map<Vertex, Record>;

void test() {
    Graph graph;
    graph["A"] = {{"B", 5}, {"D", 9}, {"E", 2}};
    graph["B"] = {{"A", 5}, {"C", 2}};
    graph["C"] = {{"B", 2}, {"D", 3}};
    graph["D"] = {{"A", 9}, {"F", 2}, {"C", 3}};
    graph["E"] = {{"A", 2}, {"F", 3}};
    graph["F"] = {{"E", 3}, {"D", 2}};

    Table table;
    table["A"] = Record{INFINITY, ""};
    table["B"] = Record{INFINITY, ""};
    table["C"] = Record{INFINITY, ""};
    table["D"] = Record{INFINITY, ""};
    table["E"] = Record{INFINITY, ""};
    table["F"] = Record{INFINITY, ""};

    auto shortest_distance_table = find_shortest_path(graph, table, Vertex{"A"});

    for (auto k : keys(shortest_distance_table)) {
        std::cout << k << " - " << shortest_distance_table[k] << "\n";
    }
}

int main() {
    test();
}
