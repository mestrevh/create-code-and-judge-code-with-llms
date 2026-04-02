/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    if (!(cin >> m)) return 0;

    vector<list<int>> table(m);
    int total_elements = 0;

    char op;
    while (cin >> op && op != 'f') {
        if (op == 'a') {
            int k;
            cin >> k;
            int h = k % m;
            auto& bucket = table[h];
            auto it = bucket.begin();
            while (it != bucket.end() && *it < k) {
                ++it;
            }
            bucket.insert(it, k);
            total_elements++;
        } else if (op == 'r') {
            int k;
            cin >> k;
            int h = k % m;
            auto& bucket = table[h];
            for (auto it = bucket.begin(); it != bucket.end(); ++it) {
                if (*it == k) {
                    bucket.erase(it);
                    total_elements--;
                    break;
                }
            }
        } else if (op == 'i') {
            cout << "imprimindo tabela hash:\n";
            for (int i = 0; i < m; ++i) {
                cout << "[" << i << "]:";
                if (table[i].empty()) {
                    cout << "Lista vazia!\n";
                } else {
                    for (int x : table[i]) {
                        cout << x << "=>";
                    }
                    cout << "\n";
                }
            }
        } else if (op == 'p') {
            int k;
            cin >> k;
            int h = k % m;
            auto& bucket = table[h];
            int count = 0;
            bool found = false;
            for (int x : bucket) {
                count++;
                if (x == k) {
                    found = true;
                    break;
                }
                if (x > k) break;
            }
            if (!found) count = 0;
            
            cout << "BUSCA POR " << k << "\n";
            cout << "numero de elementos da tabela hash: " << total_elements << "\n";
            if (found) {
                cout << "elemento " << k << " encontrado!\n";
            } else {
                cout << "elemento nao encontrado!\n";
            }
            cout << "numero de elementos acessados na tabela hash: " << count << "\n";
        }
    }

    return 0;
}