/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct NodeL {
    int id, left, center;
};

struct NodeR {
    int id, center, right;
};

set<int> nodes;

void addNodesL(int id, const vector<NodeL>& leftTree) {
    if (id == 0) return;
    if (nodes.insert(id).second) {
        addNodesL(leftTree[id - 1].left, leftTree);
        addNodesL(leftTree[id - 1].center, leftTree);
    }
}

void addNodesR(int id, const vector<NodeR>& rightTree) {
    if (id == 0) return;
    if (nodes.insert(id).second) {
        addNodesR(rightTree[id - 1].center, rightTree);
        addNodesR(rightTree[id - 1].right, rightTree);
    }
}

int main() {
    int N, M;
    cin >> N;
    vector<NodeL> leftTree(N);
    for (int i = 0; i < N; ++i) {
        cin >> leftTree[i].id >> leftTree[i].left >> leftTree[i].center;
    }

    cin >> M;
    vector<NodeR> rightTree(M);
    for (int i = 0; i < M; ++i) {
        cin >> rightTree[i].id >> rightTree[i].center >> rightTree[i].right;
    }

    addNodesL(1, leftTree);
    addNodesR(1, rightTree);

    cout << nodes.size() << endl;
    return 0;
}
