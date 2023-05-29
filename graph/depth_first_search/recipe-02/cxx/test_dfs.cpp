#include "depth_first_search.hpp"

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
    graph["A"] = {"B", "S"};
    graph["B"] = {"A"};
    graph["S"] = {"A","G","C"};
    graph["D"] = {"C"};
    graph["G"] = {"S","F","H"};
    graph["H"] = {"G","E"};
    graph["E"] = {"C","H"};
    graph["F"] = {"C","G"};
    graph["C"] = {"D","S","E","F"};

    print(depth_first_search(graph, std::string("A")));
}

int main() {
    test();
}

