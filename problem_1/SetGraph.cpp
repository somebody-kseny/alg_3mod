#include "SetGraph.hpp"

Graph::Graph(int _verticesCount): verticesCount(_verticesCount) {
    for(int i = 0; i < verticesCount; i++){
        forest.emplace_back(std::multiset<int>());
    }
}

Graph::Graph(): Graph(10) {}

Graph::Graph(const Graph & _given): verticesCount(_given.verticesCount), forest(_given.forest) {}

void Graph::AddEdge(int from, int to) {
    if(from >= verticesCount || to >= verticesCount){
        return;
    }
    forest.at(from).insert(to);
}

int Graph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> Graph::GetNextVertices(int vertex) const {
    if(vertex >= verticesCount){
        return std::vector<int>();
    }
    std::vector<int> res;
    for(auto &it: forest.at(vertex)){
        res.emplace_back(it);
    }
    return res;
}

std::vector<int> Graph::GetPrevVertices(int vertex) const {
    if(vertex >= verticesCount){
        return std::vector<int>();
    }
    std::vector<int> res;
    for(int j = 0; j < verticesCount; j++){
        for(int i = 0; i < forest.at(j).count(vertex); i++){
            res.emplace_back(j);
        }
    }
    return res;
}
