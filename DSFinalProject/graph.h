#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <unordered_map>
#include <string>

//class definition for the Graph
class Graph {
public:
    //constructor
    Graph();

    //destructor
    ~Graph();

    //add a vertex to the graph
    void addVertex(const std::string& vertex);

    //add edge with a weight between two vertices
    void addEdge(const std::string& src, const std::string& dest, int weight);

    //get the neighbors of a given vertex
    std::vector<std::string> getNeighbors(const std::string& vertex) const;

    //get the weight of the edge between two vertices
    int getEdgeWeight(const std::string& src, const std::string& dest) const;

    //display the adjacency list of the graph
    void display() const;

private:
    //represent an edge with a destination and weight
    struct Edge {
        std::string dest;
        int weight;
        Edge(const std::string& dest, int weight) : dest(dest), weight(weight) {}
    };

    //adjacency list
    std::unordered_map<std::string, std::list<Edge>> adjList;
};

#endif // GRAPH_H