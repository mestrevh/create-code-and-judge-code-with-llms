/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    int total_distancia = 0;
    for (int i = 0; i < n; ++i) {
        int t, v;
        std::cin >> t >> v;
        total_distancia += t * v;
    }
    std::cout << total_distancia << std::endl;
    return 0;
}
