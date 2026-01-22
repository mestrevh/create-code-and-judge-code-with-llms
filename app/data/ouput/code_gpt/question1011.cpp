/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class UnionFind {
public:
    UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; ++i) 
            parent[i] = i;
    }

    int find(int p) {
        if (parent[p] != p)
            parent[p] = find(parent[p]);
        return parent[p];
    }

    void unionSets(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP != rootQ) {
            if (rank[rootP] > rank[rootQ]) 
                parent[rootQ] = rootP;
            else if (rank[rootP] < rank[rootQ]) 
                parent[rootP] = rootQ;
            else {
                parent[rootQ] = rootP;
                ++rank[rootP];
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        UnionFind uf(N + 1);
        unordered_set<int> people;
        
        for (int i = 0; i < M; ++i) {
            int A, B;
            cin >> A >> B;
            uf.unionSets(A, B);
            people.insert(A);
            people.insert(B);
        }

        vector<int> groupSize(N + 1, 0);
        for (int person : people) {
            groupSize[uf.find(person)]++;
        }

        int maxSize = *max_element(groupSize.begin(), groupSize.end());
        cout << maxSize << endl;
    }
    return 0;
}
