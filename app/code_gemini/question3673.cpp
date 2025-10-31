/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

std::string removeRepetidos(std::string txt) {
    if (txt.length() <= 1) {
        return txt;
    }

    if (txt[0] == txt[1]) {
        return removeRepetidos(txt.substr(1));
    } else {
        return txt[0] + removeRepetidos(txt.substr(1));
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string linha;
    while (std::getline(std::cin, linha) && linha != "*") {
        std::cout << removeRepetidos(linha) << std::endl;
    }

    return 0;
}
