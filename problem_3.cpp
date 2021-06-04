/*
Задача 3
Требуется отыскать самый выгодный маршрут между городами.
Требования: время работы O((N+M)logN), где N-количество городов, M-известных дорог между ними.
Формат входных данных.
Первая строка содержит число N – количество городов.
Вторая строка содержит число M - количество дорог.
Каждая следующая строка содержит описание дороги (откуда, куда, время в пути).
Последняя строка содержит маршрут (откуда и куда нужно доехать).
Формат выходных данных.
Вывести длину самого выгодного маршрута.
*/

#include <iostream>
#include <vector>
#include <set>


class ArcGraph {
public:
    ~ArcGraph() = default ;
    ArcGraph(): ArcGraph(10) {};
    ArcGraph(int _verticesCount);

    void AddEdge (uint from, uint to, uint weithg);
    uint VerticesCount() const;
    void GetNextVertices(uint vertex, std::vector<std::pair<uint,uint>>& res) const;

private:
    uint verticesCount;
    std::vector<std::vector<std::pair<uint,uint>>> buf;
};

ArcGraph::ArcGraph(int _verticesCount): verticesCount(_verticesCount) {
    buf.resize(_verticesCount);
}

uint ArcGraph::VerticesCount() const {
    return verticesCount;
}

void ArcGraph::AddEdge (uint from, uint to, uint weigth) {
buf.at(from).emplace_back(to, weigth);
buf.at(to).emplace_back(from, weigth);
}

void ArcGraph::GetNextVertices(uint vertex, std::vector<std::pair<uint,uint>>& res) const {
    res = buf.at(vertex);
}


int getLengthOfShortestWay(ArcGraph& graph, uint from, uint to ) {
    uint vert_count = graph.VerticesCount();

    int visited = 0;
    std::vector<int> distances = std::vector<int>(vert_count, -1);
    distances[from] = 0;
    std::set<std::pair<int, uint>> q;
    q.emplace( 0, from);

    std::vector<std::pair<uint,uint>> res;
    while( !q.empty() ||  visited < vert_count) {
        visited++;
        uint u = q.begin()->second;
        q.erase(q.begin());

        if (u == to){
            return distances[to];
        }

        graph.GetNextVertices(u, res);
        for( auto &v :  res) {
            if( distances[v.first] == -1 ) {
                distances[v.first] = distances[u] + (int)v.second;
                q.emplace(distances[v.first], v.first);
            } else if(distances[v.first] > distances[u] + v.second) {
                q.erase(std::make_pair(distances[v.first], v.first));
                distances[v.first] = distances[u] + (int)v.second;
                q.emplace(distances[v.first], v.first);
            }
        }
    }
    return distances[to];
}

int main(){

    int verticesCount = 0;
    std::cin >> verticesCount;
    ArcGraph graph = ArcGraph(verticesCount);

    int rebersCount;
    std::cin >> rebersCount;
    uint oneVert, twoVert, weight;
    for(int i = 0; i < rebersCount; i++){
        std::cin >> oneVert >> twoVert >> weight;
        graph.AddEdge(oneVert, twoVert, weight);
    }

    std::cin >> oneVert >> twoVert;
    std::cout << getLengthOfShortestWay(graph, oneVert, twoVert);
    return 0;
}