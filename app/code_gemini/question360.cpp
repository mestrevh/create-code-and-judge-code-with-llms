/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::string gabarito;
    std::string respostas;
    std::cin >> gabarito >> respostas;
    int acertos = 0;
    for (int i = 0; i < n; ++i) {
        if (gabarito[i] == respostas[i]) {
            acertos++;
        }
    }
    std::cout << acertos << std::endl;
    return 0;
}
