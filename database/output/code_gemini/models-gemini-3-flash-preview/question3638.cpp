/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problema: Substituindo palavras no texto
 * Autor: Persona (Grande Mestre em Programação Competitiva)
 * Estratégia: 
 * 1. Ler todas as linhas da entrada para separar o texto base das palavras de controle.
 * 2. Identificar a palavra alvo (target) e a palavra substituta (replacement) como as duas últimas linhas.
 * 3. Concatenar as linhas anteriores para formar o texto original.
 * 4. Utilizar o método string::find e string::replace para realizar a substituição global.
 * Complexidade: O(N * M) onde N é o tamanho do texto e M o tamanho da palavra (eficiente para N=500).
 */

int main() {
    // Otimização de I/O para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> lines;
    string current_line;

    // Leitura robusta de todas as linhas da entrada
    while (getline(cin, current_line)) {
        // Remoção de \r (CR) para compatibilidade com diferentes sistemas de fim de linha
        if (!current_line.empty() && current_line.back() == '\r') {
            current_line.pop_back();
        }
        lines.push_back(current_line);
    }

    // Tratamento para garantir que temos texto, alvo e substituto
    // De acordo com a descrição, as duas últimas strings lidas são o alvo e a substituta.
    if (lines.size() >= 3) {
        string replacement = lines.back();
        lines.pop_back();
        string target = lines.back();
        lines.pop_back();

        // Reconstrução do texto original (caso possua múltiplas linhas)
        string text = "";
        for (size_t i = 0; i < lines.size(); ++i) {
            text += lines[i];
            if (i < lines.size() - 1) {
                text += "\n";
            }
        }

        // Processo de substituição
        if (!target.empty()) {
            size_t pos = 0;
            // Busca iterativa por todas as ocorrências da string alvo
            while ((pos = text.find(target, pos)) != string::npos) {
                text.replace(pos, target.length(), replacement);
                // Avança a posição para evitar loops infinitos caso replacement contenha target
                pos += replacement.length();
            }
        }

        // Saída do texto processado
        cout << text << endl;
    } else if (lines.size() == 2) {
        // Caso atípico com apenas texto e uma palavra (não esperado pelo enunciado)
        cout << lines[0] << endl;
    }

    return 0;
}