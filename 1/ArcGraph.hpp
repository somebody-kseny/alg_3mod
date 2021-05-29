#pragma once
#include "IGraph.hpp"

class ArcGraph : IGraph {
public:
    ~ArcGraph() override = default ;
    ArcGraph(): ArcGraph(10) {};
    ArcGraph(int _verticesCount):verticesCount(_verticesCount) {};
    ArcGraph(const ArcGraph&);

    // Добавление ребра от from к to.
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex)  const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    int verticesCount;
    std::vector<std::pair<int,int>> pairs;
};

