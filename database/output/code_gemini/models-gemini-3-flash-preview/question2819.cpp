/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int interface_grafica, inteligencia_artificial, encapsulamento, indentacao, structs;
    
    if (!(std::cin >> interface_grafica >> inteligencia_artificial >> encapsulamento >> indentacao >> structs)) {
        return 0;
    }

    std::cout << "Trabalho aborda Interface Grafica? (0 - Nao 1 - Sim)\n";
    std::cout << "Trabalho aborda Inteligencia Artificial? (0 - Nao 1 - Sim)\n";
    std::cout << "Trabalho aborda Encapsulamento? (0 - Nao 1 - Sim)\n";
    std::cout << "Trabalho aborda Indentacao? (0 - Nao 1 - Sim)\n";
    std::cout << "Trabalho aborda Structs? (0 - Nao 1 - Sim)\n";

    bool req1 = (interface_grafica == 1 || inteligencia_artificial == 1);
    bool req2 = (encapsulamento == 1 && indentacao == 1);
    bool req3 = (structs == 1);

    if (req1 && req2 && req3) {
        std::cout << "Seu trabalho sera avaliado.\n";
    } else {
        std::cout << "Seu trabalho nao sera avaliado, nota 0.\n";
    }

    return 0;
}