/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

struct Node {
    string name;
    Node* parent;
    Node(string n) : name(n), parent(nullptr) {}
};

unordered_map<string, Node*> nodes;

int grau(Node* a, Node* b) {
    if (a == b) return 0;
    if (!a || !b) return numeric_limits<int>::max();
    return 1 + min(grau(a->parent, b), grau(a, b->parent));
}

pair<string, string> findFarthestRelatives(int& maxDegree) {
    pair<string, string> result;
    for (auto& entryA : nodes) {
        for (auto& entryB : nodes) {
            if (entryA.first < entryB.first) {
                int degree = grau(entryA.second, entryB.second);
                if (degree > maxDegree) {
                    maxDegree = degree;
                    result = {entryA.first, entryB.first};
                }
            }
        }
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; ++i) {
        string line, P, F;
        getline(cin, line);
        stringstream ss(line);
        ss >> P >> F;

        if (nodes.find(P) == nodes.end()) nodes[P] = new Node(P);
        if (nodes.find(F) == nodes.end()) nodes[F] = new Node(F);
        nodes[F]->parent = nodes[P];
    }

    int maxDegree = -1;
    auto farthest = findFarthestRelatives(maxDegree);

    cout << farthest.first << " " << farthest.second << " " << maxDegree << endl;

    return 0;
}
