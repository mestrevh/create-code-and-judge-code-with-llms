/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/**
 * Problema: L1Q4 - Entrando pelo Cano
 * Objetivo: Identificar qual cano (Direita, Meio, Esquerda) leva à Fortaleza do Bowser.
 * Condição: A string deve começar com 'F' (ou 'f') e terminar com 'R' (ou 'r'), 
 *           referenciando o início e o fim da frase "Fortaleza do Bowser".
 */

bool check_match(const string& s) {
    if (s.empty()) return false;
    // Converte para minúsculo para garantir case-insensitivity conforme os casos de teste
    char first = static_cast<char>(tolower(static_cast<unsigned char>(s.front())));
    char last = static_cast<char>(tolower(static_cast<unsigned char>(s.back())));
    return (first == 'f' && last == 'r');
}

int main() {
    // Otimização de I/O padrão para Programação Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string d, m, e;
    
    // Leitura das três strings (Direita, Meio, Esquerda)
    // O formato cin >> ignora espaços em branco e quebras de linha
    if (!(cin >> d >> m >> e)) return 0;

    // Verificação prioritária conforme a ordem das placas
    if (check_match(d)) {
        cout << "Direita" << endl;
    } else if (check_match(m)) {
        cout << "Meio" << endl;
    } else if (check_match(e)) {
        cout << "Esquerda" << endl;
    } else {
        // Caso nenhum cano satisfaça a condição
        cout << "Vou em frente" << endl;
    }

    return 0;
}