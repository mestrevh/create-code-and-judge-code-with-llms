/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    switch (n) {
        case 1:
            std::cout << "domingo\n";
            break;
        case 2:
            std::cout << "segunda\n";
            break;
        case 3:
            std::cout << "terca\n";
            break;
        case 4:
            std::cout << "quarta\n";
            break;
        case 5:
            std::cout << "quinta\n";
            break;
        case 6:
            std::cout << "sexta\n";
            break;
        case 7:
            std::cout << "sabado\n";
            break;
    }
    return 0;
}
