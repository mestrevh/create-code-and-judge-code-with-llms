/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/**
 * Problema: Emplacamento
 * Objetivo: Contar quantas placas não seguem o novo padrão Mercosul.
 * Padrão Mercosul: LLLD L DD (Letra, Letra, Letra, Dígito, Letra, Dígito, Dígito)
 * Complexidade: O(N * L), onde N é o número de placas e L é o comprimento da placa (7).
 */

inline bool is_letter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

inline bool is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int main() {
    // Otimização de I/O padrão para Programação Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int replace_count = 0;
    string plate;
    
    while (n--) {
        if (!(cin >> plate)) break;

        bool is_mercosul = true;
        
        // Verifica se a placa possui o comprimento correto de 7 caracteres
        if (plate.length() != 7) {
            is_mercosul = false;
        } else {
            // Padrão: LETRA (0), LETRA (1), LETRA (2), ALGARISMO (3), LETRA (4), ALGARISMO (5), ALGARISMO (6)
            if (!is_letter(plate[0])) is_mercosul = false;
            else if (!is_letter(plate[1])) is_mercosul = false;
            else if (!is_letter(plate[2])) is_mercosul = false;
            else if (!is_digit(plate[3])) is_mercosul = false;
            else if (!is_letter(plate[4])) is_mercosul = false;
            else if (!is_digit(plate[5])) is_mercosul = false;
            else if (!is_digit(plate[6])) is_mercosul = false;
        }

        // Se não segue o padrão Mercosul, ela deve ser trocada
        if (!is_mercosul) {
            replace_count++;
        }
    }

    cout << replace_count << "\n";

    return 0;
}