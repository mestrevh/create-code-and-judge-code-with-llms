/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Função recursiva que implementa a definição de MOD:
 * MOD(x, y) = MOD(|x| - |y|, |y|), se |x| >= |y|
 * MOD(x, y) = |x|, se |x| < |y|
 * Retorna -1 caso y seja 0 (divisão impossível).
 */
long long MOD(long long x, long long y) {
    if (y == 0) return -1;

    // Obtém os valores absolutos conforme a definição
    long long ax = (x < 0) ? -x : x;
    long long ay = (y < 0) ? -y : y;

    // Caso base: |x| < |y|
    if (ax < ay) {
        return ax;
    }

    // Passo recursivo: MOD(|x| - |y|, |y|)
    // Note que ax-ay e ay já são positivos, então as próximas chamadas
    // processarão os valores corretamente dentro da lógica de ax e ay.
    return MOD(ax - ay, ay);
}

int main() {
    // Otimização de entrada e saída para maratona de programação
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x, y;
    // Leitura dos valores de entrada
    if (cin >> x >> y) {
        // Chamada da função recursiva e impressão do resultado
        cout << MOD(x, y) << endl;
    }

    return 0;
}