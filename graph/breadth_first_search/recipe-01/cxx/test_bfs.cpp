#include "breadth_first_search.hpp"

#include <string>
#include <map>
#include <vector>
#include <iostream>

using Vertex = std::string;
using Graph = std::map<Vertex, std::vector<Vertex>>;

void print(std::vector<std::string> vertices) {
    bool first = true;
    std::cout << "[";
    for (const auto& elem : vertices) {
        if (first) {
            first = false;
            std::cout << "'";
        } else {
            std::cout << ", '";
        }
        std::cout << elem << "'";
    }
    std::cout << "]" << std::endl;
}

void test() {
    Graph graph;
    graph["A"] = {"B", "G", "D"};
    graph["B"] = {"A", "F", "E"};
    graph["C"] = {"F", "H"};
    graph["D"] = {"F", "A"};
    graph["E"] = {"B", "G"};
    graph["F"] = {"B", "D", "C"};
    graph["G"] = {"A", "E"};
    graph["H"] = {"C"};

    print(breadth_first_search(graph, std::string("A")));
}

int main() {
    test();
}

