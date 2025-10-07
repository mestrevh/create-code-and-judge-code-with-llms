/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
public:
    UnionFind(int size) {
        parent.resize(size + 1);
        for (int i = 1; i <= size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootY] = rootX;
        }
    }

private:
    vector<int> parent;
};

int main() {
    int N, K;
    cin >> N >> K;
    UnionFind uf(N);

    for (int i = 0; i < K; ++i) {
        char operation;
        int x, y;
        cin >> operation >> x >> y;

        if (operation == 'F') {
            uf.unite(x, y);
        } else if (operation == 'C') {
            cout << (uf.find(x) == uf.find(y) ? 'S' : 'N') << endl;
        }
    }
    return 0;
}
