/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    while (std::cin >> N && N != 0) {
        int total_varetas_para_lados = 0;
        for (int i = 0; i < N; ++i) {
            int C, V;
            std::cin >> C >> V;
            total_varetas_para_lados += (V / 2);
        }
        int retangulos = total_varetas_para_lados / 2;
        std::cout << retangulos << "\n";
    }
    return 0;
}
