/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> compras = {"leite", "manteiga", "ovos"};
    string itemToAdd, itemToRemove;

    if (!(cin >> itemToAdd)) return 0;
    if (!(cin >> itemToRemove)) {
        // Handle potential missing second input
    }

    compras.push_back(itemToAdd);

    auto it = find(compras.begin(), compras.end(), itemToRemove);
    if (it != compras.end()) {
        compras.erase(it);
    }

    cout << "[";
    for (size_t i = 0; i < compras.size(); ++i) {
        cout << "'" << compras[i] << "'";
        if (i < compras.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}