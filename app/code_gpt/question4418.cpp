/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int id;
    vector<Node*> edges;
    Node(int id) : id(id) {}
};

void addEdge(Node* from, Node* to) {
    from->edges.push_back(to);
}

void printGraph(Node* start) {
    vector<bool> visited(10, false);
    vector<Node*> stack;
    stack.push_back(start);

    while (!stack.empty()) {
        Node* current = stack.back();
        stack.pop_back();

        if (!visited[current->id]) {
            visited[current->id] = true;
            cout << ".                              |" << endl;
            cout << ".                              |" << endl;
            cout << ".                              |" << endl;
            cout << ".                        <-<-<-" << endl;
            cout << ".                        |" << endl;
            cout << ".                        |" << endl;
            cout << ".                        x" << endl;

            for (Node* neighbor : current->edges)
                stack.push_back(neighbor);
        }
    }
}

int main() {
    vector<Node*> nodes(10);
    for (int i = 0; i < 10; ++i)
        nodes[i] = new Node(i);

    addEdge(nodes[5], nodes[3]);
    addEdge(nodes[5], nodes[2]);
    addEdge(nodes[2], nodes[0]);

    printGraph(nodes[5]);

    for (Node* node : nodes)
        delete node;

    return 0;
}
