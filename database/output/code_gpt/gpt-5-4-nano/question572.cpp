/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p1, p2, p3, p4, p5;
    if (!(cin >> p1)) return 0;
    cin >> p2 >> p3 >> p4 >> p5;

    int total = 0;
    if (p1 == 0) total += 2;
    if (p2 == 1) total += 1;
    if (p3 == 1) total += 1;
    if (p4 == 1) total += 1;
    if (p5 == 1) total += 3;

    if (total >= 5) {
        cout << "A Matrix esta em todo lugar. A nossa volta. E o mundo colocado diante de seus olhos, para que nao veja a verdade. Infelizmente e impossivel dizer o que e a Matrix. Voce tem de ver por si mesmo. *Voce e sugado pelo telefone e revelado a verdade";
    } else {
        cout << "Voce precisa entender que a maioria dessas pessoas nao estao prontas para acordar. E muitos estao tao inertes, tao dependentes do sistema que vao lutar para protege-lo.";
    }
    return 0;
}