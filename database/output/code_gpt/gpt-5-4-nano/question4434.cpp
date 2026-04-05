/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Product {
    string name;
    int qty = 0;
    double price = 0.0;
    bool occupied = false;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    if (!(cin >> size)) return 0;

    vector<vector<Product>> grid(size, vector<Product>(size));

    auto findByName = [&](const string& name, int &r, int &c) -> bool {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[i][j].occupied && grid[i][j].name == name) {
                    r = i; c = j;
                    return true;
                }
            }
        }
        return false;
    };

    string op;
    cout.setf(std::ios::fixed);
    cout << setprecision(2);

    while (cin >> op) {
        if (op == "EXIT") {
            cout << "Saindo..." << '\n';
            break;
        } else if (op == "CREATE") {
            int r, c;
            string name;
            int qty;
            double price;
            cin >> r >> c >> name >> qty >> price;
            if (r < 0 || r >= size || c < 0 || c >= size) {
                cout << "ERRO: espaço ja ocupado" << '\n';
                continue;
            }
            if (!grid[r][c].occupied) {
                grid[r][c].occupied = true;
                grid[r][c].name = name;
                grid[r][c].qty = qty;
                grid[r][c].price = price;
                cout << "Produto adicionado no estoque!" << '\n';
            } else {
                cout << "ERRO: espaço ja ocupado" << '\n';
            }
        } else if (op == "READ") {
            string name;
            cin >> name;
            int r = -1, c = -1;
            if (!findByName(name, r, c)) {
                continue;
            }
            cout << "LINHA: " << r << " COLUNA: " << c << " QTD: " << grid[r][c].qty
                 << " PRECO: " << grid[r][c].price << '\n';
        } else if (op == "UPDATE") {
            string name;
            int qty;
            double price;
            cin >> name >> qty >> price;
            int r = -1, c = -1;
            if (!findByName(name, r, c)) {
                cout << "Produto nao encontrado!" << '\n';
            } else {
                grid[r][c].qty = qty;
                grid[r][c].price = price;
                cout << "Produto atualizado!" << '\n';
            }
        } else if (op == "DELETE") {
            string name;
            cin >> name;
            int r = -1, c = -1;
            if (!findByName(name, r, c)) {
                cout << "Produto nao encontrado!" << '\n';
            } else {
                grid[r][c].occupied = false;
                grid[r][c].name.clear();
                grid[r][c].qty = 0;
                grid[r][c].price = 0.0;
                cout << "Produto removido!" << '\n';
            }
        } else if (op == "PRINT") {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (!grid[i][j].occupied) continue;
                    cout << "LINHA: " << i << " COLUNA: " << j << " NOME: " << grid[i][j].name
                         << " QTD: " << grid[i][j].qty << " PRECO: " << grid[i][j].price << '\n';
                }
            }
        }
    }

    return 0;
}