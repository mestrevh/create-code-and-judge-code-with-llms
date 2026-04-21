/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Product {
    string name;
    int qty;
    double price;
    bool active;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<vector<Product>> grid(N, vector<Product>(N, {"", 0, 0.0, false}));

    string cmd;
    while (cin >> cmd) {
        if (cmd == "EXIT") {
            cout << "Saindo..." << endl;
            break;
        } else if (cmd == "CREATE") {
            int r, c;
            cin >> r >> c;
            if (r >= 0 && r < N && c >= 0 && c < N) {
                if (!grid[r][c].active) {
                    string n;
                    int q;
                    double p;
                    cin >> n >> q >> p;
                    grid[r][c] = {n, q, p, true};
                    cout << "Produto adicionado no estoque!" << endl;
                } else {
                    cout << "ERRO: espaco ja ocupado" << endl;
                }
            }
        } else if (cmd == "READ") {
            string name;
            cin >> name;
            bool found = false;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (grid[i][j].active && grid[i][j].name == name) {
                        cout << "LINHA: " << i << " COLUNA: " << j << " QTD: " << grid[i][j].qty << " PRECO: " << fixed << setprecision(2) << grid[i][j].price << endl;
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
        } else if (cmd == "UPDATE") {
            string name;
            cin >> name;
            int nQty;
            double nPrice;
            cin >> nQty >> nPrice;
            bool found = false;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (grid[i][j].active && grid[i][j].name == name) {
                        grid[i][j].qty = nQty;
                        grid[i][j].price = nPrice;
                        cout << "Produto atualizado!" << endl;
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
            if (!found) {
                cout << "Produto nao encontrado!" << endl;
            }
        } else if (cmd == "DELETE") {
            string name;
            cin >> name;
            bool found = false;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (grid[i][j].active && grid[i][j].name == name) {
                        grid[i][j].active = false;
                        cout << "Produto removido!" << endl;
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
            if (!found) {
                cout << "Produto nao encontrado!" << endl;
            }
        } else if (cmd == "PRINT") {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (grid[i][j].active) {
                        cout << "LINHA: " << i << " COLUNA: " << j << " NOME: " << grid[i][j].name << " QTD: " << grid[i][j].qty << " PRECO: " << fixed << setprecision(2) << grid[i][j].price << endl;
                    }
                }
            }
        }
    }

    return 0;
}