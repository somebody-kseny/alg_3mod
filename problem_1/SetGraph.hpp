#pragma once
#include "IGraph.hpp"
#include <set>

class Graph : IGraph {
public:
    ~Graph() override = default ;
    Graph();
    Graph(int _verticesCount);
    Graph(const Graph&);

    // Добавление ребра от from к to.
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex)  const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    int verticesCount;
    std::vector<std::multiset<int>> forest;
};

