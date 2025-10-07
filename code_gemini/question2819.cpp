/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int gui, ai, encap, indent, structs;
    
    std::cin >> gui >> ai >> encap >> indent >> structs;
    
    std::cout << "Trabalho aborda Interface Grafica? (0 - Nao 1 - Sim)" << std::endl;
    std::cout << "Trabalho aborda Inteligencia Artificial? (0 - Nao 1 - Sim)" << std::endl;
    std::cout << "Trabalho aborda Encapsulamento? (0 - Nao 1 - Sim)" << std::endl;
    std::cout << "Trabalho aborda Indentacao? (0 - Nao 1 - Sim)" << std::endl;
    std::cout << "Trabalho aborda Structs? (0 - Nao 1 - Sim)" << std::endl;
    
    bool req1 = (gui == 1 || ai == 1);
    bool req2 = (encap == 1 && indent == 1);
    bool req3 = (structs == 1);
    
    if (req1 && req2 && req3) {
        std::cout << "Seu trabalho sera avaliado." << std::endl;
    } else {
        std::cout << "Seu trabalho nao sera avaliado, nota 0." << std::endl;
    }
    
    return 0;
}
