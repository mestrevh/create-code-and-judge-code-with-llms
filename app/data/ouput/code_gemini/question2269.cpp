/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int v, d;
    std::cin >> v >> d;
    
    long long total_cost = 0;
    int total_bowls = 0;
    
    for (int i = 0; i < d; ++i) {
        int t;
        std::cin >> t;
        total_bowls += t;
        
        if (t == 1) {
            total_cost += 10;
        } else if (t >= 2 && t <= 10) {
            total_cost += t * 9;
        } else if (t > 10) {
            total_cost += t * 8;
        }
    }
    
    if (total_bowls == 0) {
        std::cout << "Naruto nao apareceu para comer\n";
    } else {
        if (v >= total_cost) {
            std::cout << "Naruto conseguiu pagar a sua conta!\n";
        } else {
            long long falta = total_cost - v;
            std::cout << "Naruto, faltam " << falta << " ryos!\n";
        }
    }
    
    return 0;
}
