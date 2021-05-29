#include "MatrixGraph.hpp"

MatrixGraph::MatrixGraph(int _verticesCount): verticesCount(_verticesCount) {
    std::vector<int> row = std::vector<int>(verticesCount, 0);
    for(int i = 0; i < verticesCount; i++){
        table.emplace_back(row);
    }
}

MatrixGraph::MatrixGraph(): MatrixGraph(10) {

}

MatrixGraph::MatrixGraph(const MatrixGraph & _given): verticesCount(_given.verticesCount), table(_given.table) {}

void MatrixGraph::AddEdge(int from, int to) {
    if(from >= verticesCount || to >= verticesCount){
        return;
    }
    table.at(from).at(to) += 1;
}

int MatrixGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    if(vertex >= verticesCount){
        return std::vector<int>();
    }
    std::vector<int> res;
    int amount_repeates = 0;
    for(int i = 0; i < verticesCount; i++){
        amount_repeates = table.at(vertex).at(i);
        for(int j = 0; j < amount_repeates; j++){
            res.emplace_back(i);
        }
    }
    return res;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    if(vertex >= verticesCount){
        return std::vector<int>();
    }
    std::vector<int> res;
    int amount_repeates = 0;
    for(int i = 0; i < verticesCount; i++){
        amount_repeates = table.at(i).at(vertex);
        for(int j = 0; j < amount_repeates; j++){
            res.emplace_back(i);
        }
    }
    return res;
}

