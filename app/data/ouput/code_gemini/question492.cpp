/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int total_capsulas = 0;
    for (int i = 0; i < 7; ++i) {
        int quantidade;
        char tipo;
        std::cin >> quantidade >> tipo;
        if (tipo == 'p' || tipo == 'P') {
            total_capsulas += quantidade * 10;
        } else if (tipo == 'g' || tipo == 'G') {
            total_capsulas += quantidade * 16;
        }
    }
    int xicaras_por_professor = (total_capsulas * 2) / 7;
    std::cout << total_capsulas << std::endl;
    std::cout << xicaras_por_professor << std::endl;
    return 0;
}
