#include "graph.h"
#include <iostream>

Graph::Graph() {}

Graph::~Graph() {}

void Graph::addVertex(const std::string& vertex) {
    if (adjList.find(vertex) == adjList.end()) {
        adjList[vertex] = std::list<Edge>();
    }
}

void Graph::addEdge(const std::string& src, const std::string& dest, int weight) {
    if (adjList.find(src) != adjList.end() && adjList.find(dest) != adjList.end()) {
        adjList[src].emplace_back(dest, weight);
    }
}

std::vector<std::string> Graph::getNeighbors(const std::string& vertex) const {
    std::vector<std::string> neighbors;
    if (adjList.find(vertex) != adjList.end()) {
        for (const auto& edge : adjList.at(vertex)) {
            neighbors.push_back(edge.dest);
        }
    }
    return neighbors;
}

int Graph::getEdgeWeight(const std::string& src, const std::string& dest) const {
    if (adjList.find(src) != adjList.end()) {
        for (const auto& edge : adjList.at(src)) {
            if (edge.dest == dest) {
                return edge.weight;
            }
        }
    }
    return -1; // Indicating no edge exists
}

void Graph::display() const {
    for (const auto& pair : adjList) {
        const std::string& vertex = pair.first;
        std::cout << vertex << ": ";
        for (const auto& edge : pair.second) {
            std::cout << edge.dest << "(" << edge.weight << ") ";
        }
        std::cout << std::endl;
    }
}
