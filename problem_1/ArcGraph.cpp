#include "ArcGraph.hpp"

ArcGraph::ArcGraph(const ArcGraph & _given):verticesCount(_given.VerticesCount()), pairs(_given.pairs) {}

void ArcGraph::AddEdge(int from, int to) {
    pairs.emplace_back(std::make_pair(from,to));
}

int ArcGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> res;
    for(auto it: pairs){
        if(it.first == vertex){
            res.emplace_back(it.second);
        }
    }
    return res;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> res;
    for(auto it: pairs){
        if(it.second == vertex){
            res.emplace_back(it.first);
        }
    }
    return res;
}
