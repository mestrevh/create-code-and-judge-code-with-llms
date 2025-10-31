/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int idade;
    char sexo;
    int contador = 0;
    while (std::cin >> idade && idade != 111) {
        std::cin >> sexo;
        if (idade <= 10 || idade > 60) {
            contador++;
        } else if ((sexo == 'M' || sexo == 'm') && idade > 25 && idade < 35) {
            contador++;
        }
    }
    std::cout << contador << std::endl;
    return 0;
}
