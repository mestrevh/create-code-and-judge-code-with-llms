/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    // Otimização de I/O padrão para C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    // O problema solicita o processamento de uma string Beiju.
    // O loop while permite lidar com múltiplos casos de teste se fornecidos, 
    // ou apenas um conforme a descrição, respeitando o formato de entrada.
    while (cin >> input) {
        // Utilização da estrutura de dados Linked List (std::list no C++ moderno)
        // std::list é uma doubly linked list que permite inserções O(1) em qualquer posição.
        list<char> text;
        
        // O iterador 'cursor' funciona como o cursor do teclado.
        // Inicialmente ele aponta para o fim da lista.
        auto cursor = text.begin();

        for (char c : input) {
            if (c == '[') {
                // Tecla Home: Move o cursor para o início da lista.
                cursor = text.begin();
            } else if (c == ']') {
                // Tecla End: Move o cursor para o fim da lista.
                cursor = text.end();
            } else {
                // Insere o caractere na posição atual do cursor.
                // Na std::list, a inserção ocorre antes da posição apontada pelo iterador.
                // O iterador permanece válido e aponta para o mesmo elemento (ou end()),
                // simulando perfeitamente o comportamento de um cursor de texto que "empurra"
                // o texto à direita conforme novos caracteres são digitados.
                text.insert(cursor, c);
            }
        }

        // Impressão da lista final resultante (Beiju Text).
        for (char c : text) {
            cout << c;
        }
        cout << "\n";
    }

    return 0;
}