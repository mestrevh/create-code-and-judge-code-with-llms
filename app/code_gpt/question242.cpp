/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <list>
#include <sstream>

using namespace std;

int main() {
    int N;
    cin >> N;

    while (N--) {
        int M, C;
        cin >> M >> C;

        vector<list<int>> hashTable(M);
        int key;

        for (int i = 0; i < C; i++) {
            cin >> key;
            hashTable[key % M].push_back(key);
        }

        for (int i = 0; i < M; i++) {
            cout << i << " -> ";
            for (auto it = hashTable[i].begin(); it != hashTable[i].end(); ++it) {
                if (it != hashTable[i].begin()) cout << " -> ";
                cout << *it;
            }
            cout << " -> \n";
        }
        if (N > 0) cout << "\n";
    }

    return 0;
}
