/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <list>
#include <iomanip>

using namespace std;

/**
 * Função para calcular a média dos valores de uma lista.
 * Retorna um valor real (double) para garantir a precisão de duas casas decimais,
 * conforme solicitado na descrição principal ("valor real indicando a média").
 */
double calcular_media(const list<int>& L, int n) {
    if (n <= 0) return 0.0;
    long long soma = 0;
    for (int valor : L) {
        soma += valor;
    }
    return static_cast<double>(soma) / n;
}

int main() {
    // Otimização de I/O padrão de C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Leitura do tamanho n no programa principal
    if (!(cin >> n)) return 0;

    // (b) a sequência deve ser armazenada em uma lista;
    // (c) não usar append(), a lista deve ser criada já com o tamanho necessário;
    list<int> L(n);

    // Leitura dos n itens no programa principal
    for (int &item : L) {
        cin >> item;
    }

    // Chamada da função passando a lista L e o tamanho n
    double media = calcular_media(L, n);

    // (a) o programa principal deverá imprimir um número real com duas casas pós-vírgula
    cout << fixed << setprecision(2) << media << endl;

    return 0;
}