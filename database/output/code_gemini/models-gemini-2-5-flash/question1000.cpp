/*
Código criado pelo models/gemini-2.5-flash
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector> // Embora vector não seja estritamente necessário para esta solução, string::push_back é eficiente para o tamanho de input.

// Função auxiliar para verificar se um caractere é uma vogal
inline bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    // Otimizações padrão de I/O em C++ para programação competitiva
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s; // Lê a string de entrada

    std::string vowels_only;
    // Percorre a string de entrada para extrair apenas as vogais
    for (char c : s) {
        if (isVowel(c)) {
            vowels_only.push_back(c);
        }
    }

    // Verifica se a sequência de vogais é um palíndromo
    bool is_palindrome = true;
    int n = vowels_only.length();
    for (int i = 0; i < n / 2; ++i) {
        // Compara caracteres do início e do final da sequência
        if (vowels_only[i] != vowels_only[n - 1 - i]) {
            is_palindrome = false;
            break; // Não é um palíndromo, pode sair do loop
        }
    }

    // Imprime o resultado
    if (is_palindrome) {
        std::cout << "S\n";
    } else {
        std::cout << "N\n";
    }

    return 0;
}