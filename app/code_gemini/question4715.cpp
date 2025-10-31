/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

void sequencia_aritmetica(int inicial, int razao, int termos) {
    long long termo_atual = inicial;
    for (int i = 0; i < termos; ++i) {
        std::cout << termo_atual << "\n";
        termo_atual += razao;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int inicial, razao, termos;
    std::cin >> inicial >> razao >> termos;

    sequencia_aritmetica(inicial, razao, termos);

    return 0;
}
