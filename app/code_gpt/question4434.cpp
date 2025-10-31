/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

struct Product {
    std::string name;
    int quantity;
    double price;
};

class Stock {
    std::vector<std::vector<Product*>> inventory;
    int size;

public:
    Stock(int n) : size(n) {
        inventory.resize(size, std::vector<Product*>(size, nullptr));
    }

    bool create(int row, int col, const std::string& name, int qty, double price) {
        if (inventory[row][col] == nullptr) {
            inventory[row][col] = new Product{name, qty, price};
            std::cout << "Produto adicionado no estoque!" << std::endl;
            return true;
        } else {
            std::cout << "ERRO: espaço ja ocupado" << std::endl;
            return false;
        }
    }

    void read(const std::string& name) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (inventory[i][j] && inventory[i][j]->name == name) {
                    std::cout << "LINHA: " << i << " COLUNA: " << j << " QTD: " << inventory[i][j]->quantity 
                              << " PRECO: " << std::fixed << std::setprecision(2) << inventory[i][j]->price << std::endl;
                    return;
                }
            }
        }
        std::cout << "Produto nao encontrado!" << std::endl;
    }

    bool update(const std::string& name, int qty, double price) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (inventory[i][j] && inventory[i][j]->name == name) {
                    inventory[i][j]->quantity = qty;
                    inventory[i][j]->price = price;
                    std::cout << "Produto atualizado!" << std::endl;
                    return true;
                }
            }
        }
        std::cout << "Produto nao encontrado!" << std::endl;
        return false;
    }

    bool remove(const std::string& name) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (inventory[i][j] && inventory[i][j]->name == name) {
                    delete inventory[i][j];
                    inventory[i][j] = nullptr;
                    std::cout << "Produto removido!" << std::endl;
                    return true;
                }
            }
        }
        std::cout << "Produto nao encontrado!" << std::endl;
        return false;
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (inventory[i][j]) {
                    std::cout << "LINHA: " << i << " COLUNA: " << j << " NOME: " << inventory[i][j]->name 
                              << " QTD: " << inventory[i][j]->quantity 
                              << " PRECO: " << std::fixed << std::setprecision(2) << inventory[i][j]->price << std::endl;
                }
            }
        }
    }

    ~Stock() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                delete inventory[i][j];
            }
        }
    }
};

int main() {
    int size;
    std::cin >> size;
    Stock stock(size);
    std::string command;

    while (std::cin >> command) {
        if (command == "CREATE") {
            int row, col, qty;
            std::string name;
            double price;
            std::cin >> row >> col >> name >> qty >> price;
            stock.create(row, col, name, qty, price);
        } else if (command == "READ") {
            std::string name;
            std::cin >> name;
            stock.read(name);
        } else if (command == "UPDATE") {
            std::string name;
            int qty;
            double price;
            std::cin >> name >> qty >> price;
            stock.update(name, qty, price);
        } else if (command == "DELETE") {
            std::string name;
            std::cin >> name;
            stock.remove(name);
        } else if (command == "PRINT") {
            stock.print();
        } else if (command == "EXIT") {
            std::cout << "Saindo..." << std::endl;
            break;
        }
    }

    return 0;
}
