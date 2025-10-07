/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double n1, n2, n3;
    std::cin >> n1 >> n2 >> n3;
    double media = (n1 + n2 + n3) / 3.0;
    if (media >= 7.0) {
        std::cout << "aprovado\n";
    } else if (media < 3.0) {
        std::cout << "reprovado\n";
    } else {
        std::cout << "prova final\n";
    }
    return 0;
}
