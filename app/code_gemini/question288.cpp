/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int ig, ia, enc, ind, str;
    std::cin >> ig >> ia >> enc >> ind >> str;
    if ((ig || ia) && (enc && ind) && str) {
        std::cout << "AVALIADO\n";
    } else {
        std::cout << "0\n";
    }
    return 0;
}
