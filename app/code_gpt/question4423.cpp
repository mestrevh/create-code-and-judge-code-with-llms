/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int N, total_tacas = 0;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int nota, soma = 0, count = 0;
        while (std::cin >> nota && nota != 0) {
            soma += nota;
            count++;
        }
        if (count > 0) {
            total_tacas += std::floor(soma / static_cast<double>(count));
        }
    }
    std::cout << "Elas beberam " << total_tacas << " taças!" << std::endl;
    return 0;
}
