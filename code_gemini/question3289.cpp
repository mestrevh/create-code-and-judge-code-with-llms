/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void convertAndPrint(int h, int m) {
    if (h == 24) {
        std::cout << 0 << ":" << m << " A.M" << std::endl;
    } else if (h == 0) {
        std::cout << 12 << ":" << m << " A.M" << std::endl;
    } else if (h >= 1 && h <= 11) {
        std::cout << h << ":" << m << " A.M" << std::endl;
    } else if (h == 12) {
        std::cout << 12 << ":" << m << " P.M" << std::endl;
    } else { // h must be between 13 and 23
        std::cout << h - 12 << ":" << m << " P.M" << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int h, m;
    char colon;

    while (std::cin >> h >> colon >> m) {
        if (h == -1) {
            break;
        }
        convertAndPrint(h, m);
    }

    return 0;
}
