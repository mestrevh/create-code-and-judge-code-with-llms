/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    int idade;
    std::string sexo;
    int count = 0;

    while (true) {
        std::cin >> idade;
        if (idade == 111) break;
        std::cin >> sexo;

        if ((idade <= 10) || (idade > 60) || (sexo == "M" && idade > 25 && idade < 35)) {
            count++;
        }
    }

    std::cout << count << std::endl;
    return 0;
}
