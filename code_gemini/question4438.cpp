/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
    }

    int celebrity = -1;
    for (int i = 0; i < n; ++i) {
        bool is_celebrity = true;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (adj[i][j] == 1 || adj[j][i] == 0) {
                is_celebrity = false;
                break;
            }
        }
        if (is_celebrity) {
            celebrity = i;
            break;
        }
    }

    if (celebrity != -1) {
        cout << celebrity << endl;
    } else {
        cout << "NAO HA CELEBRIDADE" << endl;
    }

    return 0;
}
