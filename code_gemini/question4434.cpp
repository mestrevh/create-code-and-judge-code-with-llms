/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Product {
    string name;
    int quantity;
    double price;
};

int main() {
    int size;
    cin >> size;

    vector<vector<Product*>> stock(size, vector<Product*>(size, nullptr));

    string command;
    while (cin >> command && command != "EXIT") {
        if (command == "CREATE") {
            int row, col;
            string name;
            int quantity;
            double price;
            cin >> row >> col >> name >> quantity >> price;
            if (row >= 0 && row < size && col >= 0 && col < size && stock[row][col] == nullptr) {
                stock[row][col] = new Product{name, quantity, price};
                cout << "Produto adicionado no estoque!" << endl;
            } else {
                cout << "ERRO: espaço ja ocupado" << endl;
            }
        } else if (command == "READ") {
            string name;
            cin >> name;
            bool found = false;
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (stock[i][j] != nullptr && stock[i][j]->name == name) {
                        cout << "LINHA: " << i << " COLUNA: " << j << " QTD: " << stock[i][j]->quantity << " PRECO: " << fixed << setprecision(2) << stock[i][j]->price << endl;
                        found = true;
                        break;
                    }
                }
            }
            
        } else if (command == "UPDATE") {
            string name;
            int quantity;
            double price;
            cin >> name >> quantity >> price;
            bool found = false;
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (stock[i][j] != nullptr && stock[i][j]->name == name) {
                        stock[i][j]->quantity = quantity;
                        stock[i][j]->price = price;
                        cout << "Produto atualizado!" << endl;
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                cout << "Produto nao encontrado!" << endl;
            }
        } else if (command == "DELETE") {
            string name;
            cin >> name;
            bool found = false;
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (stock[i][j] != nullptr && stock[i][j]->name == name) {
                        delete stock[i][j];
                        stock[i][j] = nullptr;
                        cout << "Produto removido!" << endl;
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                cout << "Produto nao encontrado!" << endl;
            }
        } else if (command == "PRINT") {
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (stock[i][j] != nullptr) {
                        cout << "LINHA: " << i << " COLUNA: " << j << " NOME: " << stock[i][j]->name << " QTD: " << stock[i][j]->quantity << " PRECO: " << fixed << setprecision(2) << stock[i][j]->price << endl;
                    }
                }
            }
        }
    }
    cout << "Saindo..." << endl;

    return 0;
}
