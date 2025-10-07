/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int A;
    std::cin >> A;
    int proximo_ano = 1986;
    while (proximo_ano <= A) {
        proximo_ano += 76;
    }
    std::cout << proximo_ano << std::endl;
    return 0;
}
