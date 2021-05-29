#pragma once
#include "IGraph.hpp"

struct Node{
    Node(int _data):data(_data){};
    int data;
    Node* next = nullptr;
};

class  ListGraph: IGraph {
public:
    ~ListGraph() override;
    ListGraph();
    ListGraph(int _verticesCount);
    ListGraph(const ListGraph&);

    // Добавление ребра от from к to.
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex)  const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    int verticesCount;
    std::vector<Node*> nodes;
};