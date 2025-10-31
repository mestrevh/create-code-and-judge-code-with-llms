/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int mes;
    std::cin >> mes;

    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (mes >= 1 && mes <= 12) {
        std::cout << "Numero de dias do mes " << mes << " : " << days[mes] << " dias\n";
    } else {
        std::cout << "Voce entrou com um mes invalido !\n";
    }

    return 0;
}
