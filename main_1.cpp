#include <iostream>

#include "ListGraph.hpp"
#include "MatrixGraph.hpp"
#include "SetGraph.hpp"
#include "ArcGraph.hpp"

void print(std::string comment, std::vector<int>& vec){
    std::cout << comment << ": ";
    for(auto it: vec){
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

void printGraph(IGraph& graph){
    std::vector<int> vec;
    for(int i = 0; i < graph.VerticesCount(); i++){
        vec = graph.GetPrevVertices(i);
        print("prev for " + std::to_string(i), vec);
        vec = graph.GetNextVertices(i);
        print("next for " + std::to_string(i), vec);
    }
}

std::vector<int> readGraph(IGraph& graph){
    std::vector<int> vec;
    std::vector<int> vecFromGraph;
    for(int i = 0; i < graph.VerticesCount(); i++) {
        vecFromGraph = graph.GetPrevVertices(i);
        for(auto it: vecFromGraph){
            vec.emplace_back(it);
        }
        vecFromGraph = graph.GetNextVertices(i);
        for(auto it: vecFromGraph){
            vec.emplace_back(it);
        }
    }
    return vec;
};

int main(){
    int size = 6;
    ListGraph graphL = ListGraph(size);

    graphL.AddEdge(2,1);
    graphL.AddEdge(2,1);
    graphL.AddEdge(2,1);
    graphL.AddEdge(1,3);
    graphL.AddEdge(3,4);
    graphL.AddEdge(4,5);
    graphL.AddEdge(5,3);

    std::vector<std::vector<int>> graphsVec;

    graphsVec.emplace_back(readGraph(graphL));

    MatrixGraph graphM = MatrixGraph(graphL);
    graphsVec.emplace_back(readGraph(graphM));

    SetGraph graphS = SetGraph(graphM);
    graphsVec.emplace_back(readGraph(graphS));

    ArcGraph graphA = ArcGraph(graphS);
    graphsVec.emplace_back(readGraph(graphA));


    std::vector<int> prevVec = graphsVec.at(0);
    bool isOk = true;
    for(int i = 1; i < graphsVec.size(); i++){
        if(prevVec != graphsVec.at(i)){
            std::cout << "problems" << std::endl;
            isOk = false;
            break;
        }
    }
    if(isOk) std::cout << "It's ok" << std::endl;

    return 0;
}