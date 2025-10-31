/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x;
    std::cin >> x;
    int total_cost = 0;
    for (int i = 0; i < 6; ++i) {
        int v;
        std::string name;
        std::cin >> v >> name;
        total_cost += v;
    }
    if (total_cost <= x) {
        std::cout << "Mario gastara um total de R$ " << total_cost << "." << std::endl;
    } else {
        int diff = total_cost - x;
        std::cout << "Infelizmente nao sera possivel comprar tudo, faltam R$ " << diff << "." << std::endl;
    }
    return 0;
}
