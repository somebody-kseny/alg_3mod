#pragma once
#include "IGraph.hpp"

class  MatrixGraph: IGraph {
public:
    ~MatrixGraph() override = default;
    MatrixGraph();
    MatrixGraph(int _verticesCount);
    MatrixGraph(const MatrixGraph&);

    // Добавление ребра от from к to.
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex)  const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    int verticesCount;
    std::vector<std::vector<int>> table;
};