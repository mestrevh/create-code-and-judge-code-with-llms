/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Função recursiva para calcular a soma das forças maiores que 10.
 * Segue a estratégia de Divisão e Conquista conforme solicitado.
 * Complexidade de Tempo: O(N)
 * Complexidade de Espaço: O(log N) devido à pilha de recursão
 */
long long calcularForcaRec(const vector<int>& forcas, int inicio, int fim) {
    // Caso base: Quando houver apenas um elemento no array (impossível particionar mais)
    if (inicio == fim) {
        if (forcas[inicio] > 10) {
            return (long long)forcas[inicio];
        } else {
            return 0;
        }
    }

    // Particionar o grupo em 2 subgrupos
    int meio = inicio + (fim - inicio) / 2;

    // Aplicar a função recursiva na metade esquerda e na metade direita
    long long somaEsquerda = calcularForcaRec(forcas, inicio, meio);
    long long somaDireita = calcularForcaRec(forcas, meio + 1, fim);

    // Retornar a soma dos resultados das duas partes
    return somaEsquerda + somaDireita;
}

int main() {
    // Otimização de I/O padrão em C++ para programação competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // Tenta ler N, caso falhe ou N seja 0, encerra
    if (!(cin >> N) || N <= 0) {
        if (N == 0) cout << 0 << "\n";
        return 0;
    }

    vector<int> forcas(N);
    for (int i = 0; i < N; ++i) {
        cin >> forcas[i];
    }

    // Chama a função recursiva abrangendo todo o array
    cout << calcularForcaRec(forcas, 0, N - 1) << "\n";

    return 0;
}