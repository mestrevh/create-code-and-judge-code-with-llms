/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Otimização de I/O padrão para Programação Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Tenta ler o número de partidas. Se não houver entrada, encerra.
    if (!(cin >> n)) return 0;

    // Embora o enunciado mencione Lista Encadeada, em Programação Competitiva 
    // um vector (array dinâmico) é preferível por performance de cache (O(N)).
    // Caso o problema fosse estritamente acadêmico sobre a estrutura em si, 
    // usaríamos std::list, mas o objetivo é a eficiência.
    vector<string> toupeiras;
    toupeiras.reserve(n);

    for (int i = 0; i < n; ++i) {
        string nome;
        if (cin >> nome) {
            toupeiras.push_back(nome);
        }
    }

    string alvo;
    if (cin >> alvo) {
        int contador = 0;
        // Percorre a estrutura contando as ocorrências do nome alvo
        for (const string& nome : toupeiras) {
            if (nome == alvo) {
                contador++;
            }
        }
        // Saída conforme o formato especificado
        cout << contador << "\n";
    }

    return 0;
}