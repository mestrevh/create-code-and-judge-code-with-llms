/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q1, q2, q3, q4, q5;
    if (!(cin >> q1 >> q2 >> q3 >> q4 >> q5)) return 0;

    int points = 0;
    if (q1 == 0) points += 2;
    if (q2 == 1) points += 1;
    if (q3 == 1) points += 1;
    if (q4 == 1) points += 1;
    if (q5 == 1) points += 3;

    if (points >= 5) {
        cout << "A Matrix esta em todo lugar. A nossa volta. E o mundo colocado diante de seus olhos, para que nao veja a verdade. Infelizmente e impossivel dizer o que e a Matrix. Voce tem de ver por si mesmo. *Voce e sugado pelo telefone e revelado a verdade" << endl;
    } else {
        cout << "Voce precisa entender que a maioria dessas pessoas nao estao prontas para acordar. E muitos estao tao inertes, tao dependentes do sistema que vao lutar para protege-lo" << endl;
    }

    return 0;
}