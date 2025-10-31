/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int sarampo = 0;
    int hepatite = 0;
    int ambas = 0;
    int idade;

    while (std::cin >> idade && idade != 100) {
        bool vacina_sarampo = false;
        bool vacina_hepatite = false;

        if (idade >= 3 && idade <= 6) {
            sarampo++;
            vacina_sarampo = true;
        }

        if (idade >= 5 && idade <= 8) {
            hepatite++;
            vacina_hepatite = true;
        }

        if (vacina_sarampo && vacina_hepatite) {
            ambas++;
        }
    }

    std::cout << sarampo << std::endl;
    std::cout << hepatite << std::endl;
    std::cout << ambas << std::endl;

    return 0;
}
