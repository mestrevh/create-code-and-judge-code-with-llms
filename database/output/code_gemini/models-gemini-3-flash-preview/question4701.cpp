/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

/**
 * Função para contar as ocorrências de uma palavra em uma sequência de palavras (frase).
 * De acordo com o formato de entrada "uma palavra uma frase" e os casos de teste,
 * a primeira palavra do input é o alvo da busca e o restante do input compõe a frase.
 */
int contar_palavras_na_frase() {
    string target;
    // Lê a primeira palavra (o termo a ser contado)
    if (!(cin >> target)) {
        return 0;
    }

    string word;
    int count = 0;
    // Lê o restante da frase palavra por palavra (delimitadas por espaço/quebra de linha)
    while (cin >> word) {
        if (word == target) {
            count++;
        }
    }
    return count;
}

int main() {
    // Otimização de I/O para Programação Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Chama a função e imprime o resultado conforme o formato de saída
    cout << contar_palavras_na_frase() << endl;

    return 0;
}