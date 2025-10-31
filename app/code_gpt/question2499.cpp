/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <string>
#include <sstream>

int main() {
    std::stack<int> pilha;
    std::string comando;

    while (std::getline(std::cin, comando)) {
        if (comando == "Finalizar") break;

        std::istringstream iss(comando);
        std::string operacao;
        iss >> operacao;

        if (operacao == "Empilhar") {
            int valor;
            iss >> valor;
            pilha.push(valor);
        } else if (operacao == "Desempilhar") {
            if (!pilha.empty()) pilha.pop();
        } else if (operacao == "Imprimir") {
            std::stack<int> temp = pilha;
            std::vector<int> elementos;

            while (!temp.empty()) {
                elementos.push_back(temp.top());
                temp.pop();
            }
            for (size_t i = 0; i < elementos.size(); ++i) {
                std::cout << elementos[i];
                if (i < elementos.size() - 1) std::cout << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}
