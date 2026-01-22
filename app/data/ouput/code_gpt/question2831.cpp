/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <queue>
#include <string>

int main() {
    std::queue<int> fila;
    std::string comando;
    
    while (std::getline(std::cin, comando)) {
        if (comando == "Finalizar") break;
        
        if (comando.substr(0, 9) == "Enfileirar") {
            int valor = std::stoi(comando.substr(10));
            fila.push(valor);
        } else if (comando == "Desenfileirar") {
            if (!fila.empty()) fila.pop();
        } else if (comando == "Imprimir") {
            std::queue<int> temp = fila;
            while (!temp.empty()) {
                std::cout << temp.front() << " ";
                temp.pop();
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}
