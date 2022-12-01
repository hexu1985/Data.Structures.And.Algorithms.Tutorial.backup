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
    graph["s"] = {"a", "b"};
    graph["a"] = {"s", "c"};
    graph["b"] = {"s", "c", "d"};
    graph["c"] = {"a", "b", "d", "e"};
    graph["d"] = {"b", "c", "e"};
    graph["e"] = {"c", "d"};

    print(depth_first_search(graph, std::string("s")));
}

int main() {
    test();
}

