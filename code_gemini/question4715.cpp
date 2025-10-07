/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void sequencia_aritmetica(int inicial, int razao, int termos) {
    int atual = inicial;
    for (int i = 0; i < termos; ++i) {
        std::cout << atual << std::endl;
        atual += razao;
    }
}

int main() {
    int inicial, razao, termos;
    std::cin >> inicial >> razao >> termos;
    sequencia_aritmetica(inicial, razao, termos);
    return 0;
}
