/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d1, m1, y1, d2, m2, y2;
    char s1, s2, s3, s4;

    if (!(cin >> d1 >> s1 >> m1 >> s2 >> y1 >> d2 >> s3 >> m2 >> s4 >> y2)) {
        return 0;
    }

    // Amor calculation
    long long sumAll = (long long)d1 + m1 + y1 + d2 + m2 + y2;
    int amor = (int)((sumAll * 7) % 101);

    // Sorte calculation
    long long sumDM = (long long)d1 + d2 + m1 + m2;
    int diffY = (y1 > y2 ? y1 - y2 : y2 - y1);
    int sorte = (int)(((sumDM * 9) + diffY) % 101);

    // Trabalho calculation
    long long workVal = (long long)y1 + y2 - (sumDM * 8);
    int trabalho = (int)((workVal % 101LL + 101LL) % 101LL);

    // Cor calculation
    long long sqSum = (long long)d1 * d1 + (long long)m1 * m1 + (long long)y1 * y1 +
                      (long long)d2 * d2 + (long long)m2 * m2 + (long long)y2 * y2;
    int corIdx = (int)(sqSum % 11);

    // Output Amor
    cout << "Amor: " << amor << "% ";
    if (amor <= 33) {
        cout << "Hoje o amor nao esta para peixe. Melhor focar em voce.\n";
    } else if (amor <= 66) {
        cout << "Melhor manter o coracao <3 longe de perigo.\n";
    } else {
        cout << "Um dia deslumbrantemente lindo para amar. Ps: Cuidado com a intensidade.\n";
    }

    // Output Sorte
    cout << "Sorte: " << sorte << "% ";
    if (sorte <= 33) {
        cout << "Eita! Hoje a sorte resolveu tirar folga. Melhor nao contar com ela.\n";
    } else if (sorte <= 66) {
        cout << "A sorte esta batendo na sua porta, mas voce ainda nao abriu.\n";
    } else {
        cout << "Hoje vale a pena arriscar. Sem tigrinho nem jogos de azar, por favor!\n";
    }

    // Output Trabalho
    cout << "Trabalho: " << trabalho << "% ";
    if (trabalho <= 33) {
        cout << "Cuidado! O trabalho hoje pode ser estressante. Respire fundo.\n";
    } else if (trabalho <= 66) {
        cout << "O trabalho flui melhor se voce mantiver o foco.\n";
    } else {
        cout << "Boas vibracoes hoje, chances podem estar ao seu redor.\n";
    }

    // Output Cor
    string cores[] = {"Verde", "Amarelo", "Laranja", "Vermelho", "Roxo", "Azul", "Rosa", "Preto", "Cinza", "Marrom", "Branco"};
    cout << "Cor: " << cores[corIdx] << ".\n";

    return 0;
}