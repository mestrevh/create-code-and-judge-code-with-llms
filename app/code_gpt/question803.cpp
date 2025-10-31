/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstring>

int main() {
    char *texto = new char[1000];
    std::cin.getline(texto, 1000);
    
    int contagem[5] = {0}; // a, e, i, o, u

    for (char *p = texto; *p != '\0'; p++) {
        switch (tolower(*p)) {
            case 'a': contagem[0]++; break;
            case 'e': contagem[1]++; break;
            case 'i': contagem[2]++; break;
            case 'o': contagem[3]++; break;
            case 'u': contagem[4]++; break;
        }
    }

    std::cout << "a " << contagem[0] << std::endl;
    std::cout << "e " << contagem[1] << std::endl;
    std::cout << "i " << contagem[2] << std::endl;
    std::cout << "o " << contagem[3] << std::endl;
    std::cout << "u " << contagem[4] << std::endl;

    delete[] texto;
    return 0;
}
