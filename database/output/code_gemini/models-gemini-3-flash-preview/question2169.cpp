/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char op;
    vector<int> orders;
    orders.reserve(10001);

    while (cin >> op && op != 's') {
        if (op == 'a') {
            int val;
            cin >> val;
            orders.push_back(val);
        } else if (op == 'r') {
            int val;
            cin >> val;
            auto it = find(orders.begin(), orders.end(), val);
            if (it != orders.end()) {
                orders.erase(it);
                cout << "removido\n";
            } else {
                cout << "falha\n";
            }
        } else if (op == 'p') {
            if (orders.empty()) {
                cout << "vazia\n";
            } else {
                for (size_t i = 0; i < orders.size(); ++i) {
                    cout << orders[i] << (i == orders.size() - 1 ? "" : " ");
                }
                cout << "\n";
            }
        }
    }

    return 0;
}