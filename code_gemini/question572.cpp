/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q1, q2, q3, q4, q5;
    std::cin >> q1 >> q2 >> q3 >> q4 >> q5;

    int pontos = 0;

    if (q1 == 0) {
        pontos += 2;
    }
    if (q2 == 1) {
        pontos += 1;
    }
    if (q3 == 1) {
        pontos += 1;
    }
    if (q4 == 1) {
        pontos += 1;
    }
    if (q5 == 1) {
        pontos += 3;
    }

    if (pontos >= 5) {
        std::cout << "A Matrix esta em todo lugar. A nossa volta. E o mundo colocado diante de seus olhos, para que nao veja a verdade. Infelizmente e impossivel dizer o que e a Matrix. Voce tem de ver por si mesmo. *Voce e sugado pelo telefone e revelado a verdade\n";
    } else {
        std::cout << "Voce precisa entender que a maioria dessas pessoas nao estao prontas para acordar. E muitos estao tao inertes, tao dependentes do sistema que vao lutar para protege-lo\n";
    }

    return 0;
}
