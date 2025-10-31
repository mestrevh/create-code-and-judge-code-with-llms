/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

class HashTable {
    int m;
    list<int>* table;
    int total_elements;

public:
    HashTable(int size) : m(size), total_elements(0) {
        table = new list<int>[m];
    }

    int hash(int k) {
        return k % m;
    }

    void insert(int k) {
        int h = hash(k);
        table[h].push_back(k);
        total_elements++;
        table[h].sort();
    }

    void remove(int k) {
        int h = hash(k);
        table[h].remove(k);
        if (table[h].size() < total_elements) total_elements--;
    }

    void print() {
        for (int i = 0; i < m; i++) {
            cout << "[" << i << "]:";
            if (table[i].empty()) {
                cout << "Lista vazia!" << endl;
            } else {
                for (int val : table[i])
                    cout << val << "=>";
                cout << endl;
            }
        }
    }

    void search(int k) {
        int h = hash(k);
        int accessed = 0;
        bool found = false;

        for (int i = 0; i < m; i++) {
            accessed++;
            if (i == h) {
                for (int val : table[i]) {
                    if (val == k) {
                        found = true;
                        break;
                    }
                }
            }
        }

        cout << "BUSCA POR " << k << endl;
        cout << "numero de elementos da tabela hash: " << total_elements << endl;
        if (found) {
            cout << "elemento " << k << " encontrado!" << endl;
        } else {
            cout << "elemento nao encontrado!" << endl;
        }
        cout << "numero de elementos acessados na tabela hash: " << accessed << endl;
    }

    ~HashTable() {
        delete[] table;
    }
};

int main() {
    int m;
    cin >> m;
    HashTable ht(m);
    char command;
    int k;

    while (cin >> command) {
        if (command == 'a') {
            cin >> k;
            ht.insert(k);
        } else if (command == 'r') {
            cin >> k;
            ht.remove(k);
        } else if (command == 'i') {
            ht.print();
        } else if (command == 'p') {
            cin >> k;
            ht.search(k);
        } else if (command == 'f') {
            break;
        }
    }
    return 0;
}
