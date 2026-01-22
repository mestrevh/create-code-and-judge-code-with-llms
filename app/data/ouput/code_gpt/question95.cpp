/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

struct Item {
    std::string nome;
    double preco;
};

bool compare(const Item &a, const Item &b) {
    return a.preco < b.preco;
}

int main() {
    double D;
    std::cin >> D;
    int N;
    std::cin >> N;
    std::vector<Item> itens(N);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> itens[i].nome;
        std::cin >> itens[i].preco;
    }
    
    std::sort(itens.begin(), itens.end(), compare);
    
    std::vector<Item> escolhidos;
    double gasto = 0.0;
    
    for (const auto& item : itens) {
        if (gasto + item.preco <= D) {
            escolhidos.push_back(item);
            gasto += item.preco;
        }
    }
    
    std::sort(escolhidos.begin(), escolhidos.end(), [](const Item &a, const Item &b) {
        return a.nome < b.nome;
    });
    
    for (const auto& item : escolhidos) {
        std::cout << item.nome << " " << std::fixed << std::setprecision(2) << item.preco << std::endl;
    }
    
    std::cout << std::fixed << std::setprecision(2) << D - gasto << std::endl;
    return 0;
}
