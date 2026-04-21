/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Função para ler um vetor de números reais.
 * @param n O número de elementos a serem lidos.
 * @return Um vector contendo os elementos lidos.
 */
vector<double> ler_vetor(int n) {
    vector<double> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    return v;
}

/**
 * Função para calcular o produto interno entre dois vetores.
 * @param v1 Primeiro vetor.
 * @param v2 Segundo vetor.
 * @param n Quantidade de elementos.
 * @return O produto interno dos vetores.
 */
double calcular_produto_interno(const vector<double>& v1, const vector<double>& v2, int n) {
    double produto = 0.0;
    for (int i = 0; i < n; ++i) {
        produto += v1[i] * v2[i];
    }
    return produto;
}

int main() {
    // Otimização de I/O padrão para Programação Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Leitura do número de elementos
    if (!(cin >> n)) return 0;

    // Chamada da função de leitura duas vezes para gerar vetores independentes
    vector<double> vetor1 = ler_vetor(n);
    vector<double> vetor2 = ler_vetor(n);

    // Cálculo do produto interno chamando a função específica
    double resultado = calcular_produto_interno(vetor1, vetor2, n);

    // Saída do resultado
    cout << resultado << endl;

    return 0;
}