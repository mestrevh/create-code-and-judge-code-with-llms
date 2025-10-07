/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int E, K, N;
    std::cin >> E >> K >> N;
    for (int i = 1; i <= N; ++i) {
        int SE, SA, DO;
        std::cin >> SE >> SA >> DO;
        int saida_total = (4 * K) + SE + SA + DO;
        E -= saida_total;
        if (E <= 0) {
            std::cout << i << " " << E << std::endl;
            return 0;
        }
    }
    std::cout << E << std::endl;
    return 0;
}
