/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int pontos = 0, resposta;

    cin >> resposta;
    if (resposta == 0) pontos += 2;

    for (int i = 1; i <= 3; i++) {
        cin >> resposta;
        if (resposta == 1) pontos += 1;
    }

    cin >> resposta;
    if (resposta == 1) pontos += 3;

    if (pontos >= 5)
        cout << "A Matrix esta em todo lugar. A nossa volta. E o mundo colocado diante de seus olhos, para que nao veja a verdade. Infelizmente e impossivel dizer o que e a Matrix. Voce tem de ver por si mesmo. *Voce e sugado pelo telefone e revelado a verdade ...*";
    else
        cout << "Voce precisa entender que a maioria dessas pessoas nao estao prontas para acordar. E muitos estao tao inertes, tao dependentes do sistema que vao lutar para protege-lo";

    return 0;
}
