/*
Задача 2
Дан невзвешенный неориентированный граф. В графе может быть несколько кратчайших путей между какими-то вершинами.
Найдите количество различных кратчайших путей между заданными вершинами.
Формат ввода.
v: кол-во вершин (макс. 50000),
n: кол-во ребер (макс. 200000),
n пар реберных вершин,
пара вершин u, w для запроса.
Формат вывода.
Количество кратчайших путей от u к w.
 */

#include <iostream>
#include <climits>
#include <queue>
#include <vector>

class Graph {
public:
    ~Graph() = default ;
    Graph() = delete;
    Graph(uint16_t _verticesCount);

    void AddEdge(uint16_t from, uint16_t to);

    uint16_t VerticesCount() const;

    std::vector<uint16_t> GetNextVertices(uint16_t vertex)  const;

private:
    uint16_t verticesCount;
    std::vector<std::vector<uint16_t>> forest;
};

Graph::Graph(uint16_t _verticesCount): verticesCount(_verticesCount) {
    for(int i = 0; i < verticesCount; i++){
        forest.emplace_back(std::vector<uint16_t>());
    }
}

void Graph::AddEdge(uint16_t from, uint16_t to) {
    if(from >= verticesCount || to >= verticesCount){
        return;
    }
    forest.at(from).emplace_back(to);
}

uint16_t Graph::VerticesCount() const {
    return verticesCount;
}

std::vector<uint16_t> Graph::GetNextVertices(uint16_t vertex) const {
    if(vertex >= verticesCount){
        return std::vector<uint16_t>();
    }
    return forest.at(vertex);
}

uint16_t getAmountOfShortestWays(Graph& graph, uint16_t from, uint16_t to) {
    std::vector<int> amountOfShortWays = std::vector<int>(graph.VerticesCount(), 0);
            // количество кратчайших путей от исходной вершины до каждой другой
    std::vector<int> r = std::vector<int>(graph.VerticesCount(), INT_MAX); // длины кратчайших путей
    std::queue<int> que;
    que.push(from);
    r[from] = 0;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        int waysToW = 1;
        if (amountOfShortWays[v] > 1){
            waysToW = amountOfShortWays[v];
        }
        for(auto it: graph.GetNextVertices(v)){
            if(r[it] == r[v] + 1){
                amountOfShortWays[it] += waysToW;
            } else if (r[it] > r[v] + 1) {
                r[it] = r[v] + 1;
                amountOfShortWays[it] = waysToW;
                que.push(it);
            }
        }
    }
    return amountOfShortWays[to];
}

int main(){
    uint16_t verticesCount;
    std::cin >> verticesCount;
    Graph graph = Graph(verticesCount);

    int rebersCount;
    std::cin >> rebersCount;
    int oneVert, twoVert;
    for(int i = 0; i < rebersCount; i++){
        std::cin >> oneVert >> twoVert;
        graph.AddEdge(oneVert, twoVert);
        graph.AddEdge(twoVert, oneVert);
    }

    std::cin >> oneVert >> twoVert;
    std::cout << getAmountOfShortestWays(graph, oneVert, twoVert);
    return 0;
}