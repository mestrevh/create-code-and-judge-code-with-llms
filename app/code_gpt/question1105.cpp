/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::vector<int> valores(10);
    for (int i = 0; i < 10; ++i) {
        std::cin >> valores[i];
    }

    int maior = valores[0];
    int soma_indices = 0;

    for (int i = 0; i < 10; ++i) {
        if (valores[i] > maior) {
            maior = valores[i];
            soma_indices = i;
        } else if (valores[i] == maior) {
            soma_indices += i;
        }
    }

    std::cout << soma_indices << std::endl;
    return 0;
}
