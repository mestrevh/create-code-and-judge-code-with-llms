/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

long long somar_lista(const std::vector<int>& numeros) {
    long long soma = 0;
    for (int num : numeros) {
        soma += num;
    }
    return soma;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::getline(std::cin, line);

    std::stringstream ss(line);
    std::vector<int> numeros;
    int n;

    while (ss >> n) {
        numeros.push_back(n);
    }

    long long resultado = somar_lista(numeros);

    std::cout << resultado << std::endl;

    return 0;
}
