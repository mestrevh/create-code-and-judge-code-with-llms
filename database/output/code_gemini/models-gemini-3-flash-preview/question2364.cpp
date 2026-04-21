/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

/**
 * Função recursiva para encontrar o número mínimo de pessoas x de acordo com a fórmula:
 * f(0) = 0
 * f(1) = M
 * f(x) = x + f(x-1) se x é par
 * f(x) = M + f(x-1) se x é ímpar
 * 
 * @param x O número atual de pessoas sendo verificado.
 * @param current_f O valor acumulado f(x) até o momento.
 * @param M O valor de um ingresso básico.
 * @param target O valor alvo a ser arrecadado (10.000.000).
 * @return O valor mínimo de x para o qual f(x) >= target.
 */
int encontrar_minimo_x(int x, long long current_f, int M, long long target) {
    if (current_f >= target) {
        return x;
    }
    
    int next_x = x + 1;
    long long next_f;
    
    if (next_x % 2 == 0) {
        next_f = current_f + (long long)next_x;
    } else {
        next_f = current_f + (long long)M;
    }
    
    // A profundidade da recursão é aproximadamente 6325 no pior caso (M=0),
    // o que é seguro para a pilha de execução padrão.
    return encontrar_minimo_x(next_x, next_f, M, target);
}

int main() {
    // Otimização de I/O padrão do C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    if (!(cin >> M)) {
        return 0;
    }

    // O valor alvo é 10 milhões de dólares.
    const long long target = 10000000LL;

    // Chamada da função recursiva começando do estado inicial f(0) = 0.
    int resultado = encontrar_minimo_x(0, 0, M, target);

    // Impressão do resultado conforme o formato especificado.
    cout << resultado << " pessoas precisam assistir ao jogo." << endl;

    return 0;
}