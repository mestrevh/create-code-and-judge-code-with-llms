/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    if (!(cin >> m)) return 0;

    vector<Node*> table(m, nullptr);
    auto h = [&](int k) -> int {
        return k % m;
    };

    int nVals = 0;

    string op;
    while (cin >> op) {
        if (op == "f") break;

        if (op == "a") {
            long long kk;
            cin >> kk;
            int k = (int)kk;
            int idx = h(k);
            Node* prev = nullptr;
            Node* cur = table[idx];
            while (cur && cur->val < k) {
                prev = cur;
                cur = cur->next;
            }
            Node* nd = new Node(k);
            if (!prev) {
                nd->next = table[idx];
                table[idx] = nd;
            } else {
                nd->next = cur;
                prev->next = nd;
            }
            nVals++;
        } else if (op == "r") {
            long long kk;
            cin >> kk;
            int k = (int)kk;
            int idx = h(k);
            Node* prev = nullptr;
            Node* cur = table[idx];
            while (cur && cur->val < k) {
                prev = cur;
                cur = cur->next;
            }
            if (cur && cur->val == k) {
                if (!prev) table[idx] = cur->next;
                else prev->next = cur->next;
                delete cur;
                nVals--;
            }
        } else if (op == "i") {
            cout << "imprimindo tabela hash:\n";
            for (int i = 0; i < m; i++) {
                cout << "[" << i << "]:";
                Node* cur = table[i];
                if (!cur) {
                    cout << "Lista vazia!\n";
                } else {
                    while (cur) {
                        cout << cur->val << "=>";
                        cur = cur->next;
                    }
                    cout << "\n";
                }
            }
        } else if (op == "p") {
            long long kk;
            cin >> kk;
            int k = (int)kk;
            cout << "BUSCA POR " << k << "\n";
            int idx = h(k);
            int accessed = 0;
            bool found = false;

            Node* cur = table[idx];
            while (cur && cur->val <= k) {
                accessed++;
                if (cur->val == k) {
                    found = true;
                    break;
                }
                cur = cur->next;
            }

            cout << "numero de elementos da tabela hash: " << nVals << "\n";
            if (found) cout << "elemento " << k << " encontrado!\n";
            else cout << "elemento nao encontrado!\n";
            cout << "numero de elementos acessados na tabela hash: " << accessed << "\n";
        }
    }

    for (int i = 0; i < m; i++) {
        Node* cur = table[i];
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    return 0;
}