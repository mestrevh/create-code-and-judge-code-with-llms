/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cstdint>

using namespace std;

/**
 * A série de Fibonacci é construída como F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2).
 * Esta função utiliza recursão para percorrer até o n-ésimo termo e imprime
 * os valores na volta da recursão, resultando na ordem inversa.
 * 
 * @param current Índice atual na geração da sequência.
 * @param n Quantidade total de números a serem impressos.
 * @param a Valor de Fibonacci atual F(current).
 * @param b Valor de Fibonacci próximo F(current+1).
 */
void printFibonacciInverso(int current, int n, uint64_t a, uint64_t b) {
    if (current == n) {
        return;
    }

    // Chamada recursiva para alcançar o n-ésimo termo primeiro
    printFibonacciInverso(current + 1, n, b, a + b);

    // Impressão na volta da recursão (ordem inversa)
    cout << a << (current == 0 ? "" : " ");
}

int main() {
    // Otimização de I/O padrão Maratona/ICPC
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n) || n <= 0) {
        return 0;
    }

    // Inicia a recursão com os dois primeiros números de Fibonacci: 0 e 1
    printFibonacciInverso(0, n, 0, 1);
    cout << endl;

    return 0;
}