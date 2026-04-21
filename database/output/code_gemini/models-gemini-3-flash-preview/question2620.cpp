/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Material {
    string nome;
    long long qtd;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (n < 0) n = 0;
    vector<Material> estoque(n);
    for (int i = 0; i < n; i++) {
        cin >> estoque[i].nome >> estoque[i].qtd;
    }

    sort(estoque.begin(), estoque.end(), [](const Material& a, const Material& b) {
        return a.nome < b.nome;
    });

    vector<Material> u_estoque;
    for (int i = 0; i < n; i++) {
        if (!u_estoque.empty() && estoque[i].nome == u_estoque.back().nome) {
            u_estoque.back().qtd += estoque[i].qtd;
        } else {
            u_estoque.push_back(estoque[i]);
        }
    }

    int m;
    if (!(cin >> m)) return 0;

    while (m--) {
        string nome_req;
        long long qtd_req;
        if (!(cin >> nome_req >> qtd_req)) break;

        int low = 0, high = (int)u_estoque.size() - 1;
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (u_estoque[mid].nome == nome_req) {
                res = mid;
                break;
            } else if (u_estoque[mid].nome < nome_req) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (res != -1) {
            if (u_estoque[res].qtd >= qtd_req) {
                u_estoque[res].qtd -= qtd_req;
                cout << "Tem " << u_estoque[res].qtd << " " << nome_req << " no estoque\n";
            } else {
                cout << "Nao tem " << nome_req << " suficiente no estoque\n";
            }
        }
    }

    return 0;
}