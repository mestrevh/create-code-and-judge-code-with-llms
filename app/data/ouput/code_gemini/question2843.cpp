/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x, y;
    std::cin >> x >> y;
    int count = 0;
    for (int i = 0; i < x; ++i) {
        int current_num;
        std::cin >> current_num;
        if (current_num == y) {
            count++;
        }
    }
    std::cout << "Digite a quantidade de numeros da sequencia:\n";
    std::cout << "Digite o numero procurado:\n";
    std::cout << "O numero " << y << " apareceu na sequencia " << count << " vezes.\n";
    return 0;
}
