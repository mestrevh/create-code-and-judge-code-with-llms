/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

/**
 * Problema: Balanceamento de Parênteses e Colchetes
 * Complexidade de Tempo: O(N * L), onde N é o número de strings e L o comprimento máximo da string.
 * Complexidade de Espaço: O(L) para a pilha e armazenamento da string.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    string line;
    getline(cin, line); // Consumir a quebra de linha após a leitura de n

    while (n--) {
        if (!getline(cin, line)) break;

        stack<char> s;
        bool balanced = true;

        for (char c : line) {
            if (c == ' ') continue;

            if (c == '(' || c == '[') {
                s.push(c);
            } else if (c == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                } else {
                    balanced = false;
                    break;
                }
            } else if (c == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                } else {
                    balanced = false;
                    break;
                }
            }
        }

        if (balanced && s.empty()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}