/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    int cifra;
    std::string texto, resultado;
    std::getline(std::cin, texto);
    std::cin >> cifra;
    
    for (char &c : texto) {
        if (isalpha(c)) {
            c = toupper(c);
            c = (c - 'A' + cifra + 26) % 26 + 'A';
        }
        resultado += c;
    }
    
    std::cout << resultado << std::endl;
    return 0;
}
