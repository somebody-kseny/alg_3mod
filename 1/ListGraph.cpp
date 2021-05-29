
#include "ListGraph.hpp"

ListGraph::ListGraph(int _verticesCount): verticesCount(_verticesCount) {
    for(int i = 0; i < verticesCount; i++){
        nodes.emplace_back(new Node(i));
    }
}

ListGraph::ListGraph(): ListGraph(10) {}

ListGraph::ListGraph(const ListGraph & _given): verticesCount(_given.VerticesCount()) {
    for(int i = 0; i < verticesCount; i++){
        Node* given_node = _given.nodes.at(i);
        Node* first_node = new Node(given_node->data);
        Node* node = first_node;
        while(given_node->next){
            given_node = given_node->next;
            node->next = new Node(given_node->data);
            node = node->next;
        }
        nodes.emplace_back(first_node);
    }
}

static void removeChain(Node* node){
    if(node->next){
        if(node->next->next) removeChain(node->next);
        delete node->next;
    }
}

ListGraph::~ListGraph() {
    for(auto node: nodes){
        removeChain(node);
        delete node;
    }
}

void ListGraph::AddEdge(int from, int to) {
    if(from >= verticesCount || to >= verticesCount){
        return;
    }
    for(auto it: nodes){
        if(it->data == from){
            while (it->next){
                it = it->next;
            }
            it->next = new Node(to);
        }
    }
}

int ListGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    if(vertex >= verticesCount){
        return std::vector<int>();
    }
    std::vector<int> res;
    Node* node = nodes[vertex]->next;
    while(node){
        res.emplace_back(node->data);
        node = node->next;
    }
    return res;
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    if(vertex >= verticesCount){
        return std::vector<int>();
    }
    std::vector<int> res;
    for(auto it: nodes){
        if(it->next){
            Node* node = it;
            do {
                node = node->next;
                if(node->data == vertex){
                    res.emplace_back(it->data);
                }
            }while (node->next);
        }
    }
    return res;
}

