/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problema: Entrando pelo Cano
 * Objetivo: Identificar qual das três direções (Esquerda, Meio, Direita) 
 * contém uma string que permite formar a palavra "bowser".
 * Como "bowser" possui as letras {b, o, w, s, e, r} sem repetições,
 * basta verificar se todos esses caracteres estão presentes na string.
 */

bool can_form_bowser(const string& s) {
    bool has_b = false, has_o = false, has_w = false;
    bool has_s = false, has_e = false, has_r = false;
    
    for (char c : s) {
        if (c == 'b') has_b = true;
        else if (c == 'o') has_o = true;
        else if (c == 'w') has_w = true;
        else if (c == 's') has_s = true;
        else if (c == 'e') has_e = true;
        else if (c == 'r') has_r = true;
    }
    
    return (has_b && has_o && has_w && has_s && has_e && has_r);
}

int main() {
    // Otimização de I/O padrão para Programação Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string esquerda, meio, direita;
    
    // Leitura das três strings de entrada
    if (!(cin >> esquerda >> meio >> direita)) return 0;

    // Verificação de cada direção na ordem correta
    if (can_form_bowser(esquerda)) {
        cout << "Esquerda" << endl;
    } else if (can_form_bowser(meio)) {
        cout << "Meio" << endl;
    } else if (can_form_bowser(direita)) {
        cout << "Direita" << endl;
    }

    return 0;
}

// Complexidade de Tempo: O(N), onde N é a soma do comprimento das strings.
// Complexidade de Espaço: O(N) para armazenar as strings de entrada.