/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <set>

struct Estabelecimento {
    std::string nome;
    int x, y;
    std::string sabor;
    double preco;
    bool visitado = false;
};

long long distSq(int x1, int y1, int x2, int y2) {
    long long dx = x1 - x2;
    long long dy = y1 - y2;
    return dx * dx + dy * dy;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int current_x, current_y;
    std::cin >> current_x >> current_y;

    int n;
    std::cin >> n;

    std::vector<Estabelecimento> estabelecimentos(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> estabelecimentos[i].nome 
                 >> estabelecimentos[i].x 
                 >> estabelecimentos[i].y 
                 >> estabelecimentos[i].sabor 
                 >> estabelecimentos[i].preco;
    }

    int k;
    std::cin >> k;
    std::set<std::string> sabores_desejados;
    for (int i = 0; i < k; ++i) {
        std::string sabor;
        std::cin >> sabor;
        sabores_desejados.insert(sabor);
    }

    std::set<std::string> sabores_provados;

    for (int count = 0; count < n; ++count) {
        int best_index = -1;
        long long min_dist_sq = std::numeric_limits<long long>::max();
        double best_price = std::numeric_limits<double>::max();

        for (int i = 0; i < n; ++i) {
            if (estabelecimentos[i].visitado) {
                continue;
            }

            long long d_sq = distSq(current_x, current_y, estabelecimentos[i].x, estabelecimentos[i].y);

            if (d_sq < min_dist_sq) {
                min_dist_sq = d_sq;
                best_price = estabelecimentos[i].preco;
                best_index = i;
            } else if (d_sq == min_dist_sq) {
                if (estabelecimentos[i].preco < best_price) {
                    best_price = estabelecimentos[i].preco;
                    best_index = i;
                }
            }
        }
        
        if (best_index != -1) {
            std::cout << estabelecimentos[best_index].nome << "\n";
            
            current_x = estabelecimentos[best_index].x;
            current_y = estabelecimentos[best_index].y;
            
            estabelecimentos[best_index].visitado = true;
            
            sabores_provados.insert(estabelecimentos[best_index].sabor);
        }
    }

    bool completou_lista = true;
    if (!sabores_desejados.empty()) {
        for (const auto& sabor : sabores_desejados) {
            if (sabores_provados.find(sabor) == sabores_provados.end()) {
                completou_lista = false;
                break;
            }
        }
    }

    if (completou_lista) {
        std::cout << "Completou a lista\n";
    } else {
        std::cout << "Vou fazer as que faltaram quando chegar em casa\n";
    }

    return 0;
}
