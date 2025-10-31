/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<int> numeros(10);
    for (int i = 0; i < 10; ++i) {
        std::cin >> numeros[i];
    }
    int x;
    std::cin >> x;
    int contador = 0;
    for (int i = 0; i < 10; ++i) {
        if (numeros[i] == x) {
            contador++;
        }
    }
    std::cout << contador << std::endl;
    return 0;
}
