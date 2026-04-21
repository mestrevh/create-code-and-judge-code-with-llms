/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int x;
    cin >> x;

    // Output the original list
    cout << "[ ";
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << "]" << endl;

    // Logic for removal based on status
    if (n == 0) {
        cout << "A lista estah vazia - nao eh possivel remover elemento" << endl;
    } else {
        int target_idx = -1;
        for (int i = 0; i < n; ++i) {
            if (v[i] == x) {
                target_idx = i;
                break;
            }
        }

        if (target_idx != -1) {
            // Item found: output item and modified list
            cout << x << endl;
            cout << "[ ";
            for (int i = 0; i < n; ++i) {
                if (i == target_idx) continue;
                cout << v[i] << " ";
            }
            cout << "]" << endl;
        } else {
            // Item not found: output error message with item value
            cout << "Nao eh possivel remover o elemento " << x << endl;
        }
    }

    return 0;
}