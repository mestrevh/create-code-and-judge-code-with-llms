/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

/**
 * Funcao para retornar a precedencia dos operadores binarios.
 * Precedencia 0: +, -
 * Precedencia 1: *, /
 * Precedencia 2: ^
 */
int getPrecedence(char op) {
    if (op == '^') return 2;
    if (op == '*' || op == '/') return 1;
    if (op == '+' || op == '-') return 0;
    return -1;
}

int main() {
    // Otimizacao de I/O para Programacao Competitiva
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    while (N--) {
        string infix;
        if (!(cin >> infix)) break;

        string postfix = "";
        stack<char> s;

        for (char c : infix) {
            // Operandos (letras a-z) sao adicionados diretamente ao resultado
            if (c >= 'a' && c <= 'z') {
                postfix += c;
            }
            // Parenteses de abertura vao para a pilha
            else if (c == '(') {
                s.push(c);
            }
            // Parenteses de fechamento desempilham ate encontrar '('
            else if (c == ')') {
                while (!s.empty() && s.top() != '(') {
                    postfix += s.top();
                    s.pop();
                }
                if (!s.empty()) s.pop(); // Remove '('
            }
            // Operadores binarios
            else {
                // Enquanto o topo da pilha tiver precedencia maior ou igual, desempilha.
                // Isso assume associatividade a esquerda para os operadores.
                while (!s.empty() && s.top() != '(' && getPrecedence(s.top()) >= getPrecedence(c)) {
                    postfix += s.top();
                    s.pop();
                }
                s.push(c);
            }
        }

        // Desempilha os operadores restantes
        while (!s.empty()) {
            if (s.top() != '(') {
                postfix += s.top();
            }
            s.pop();
        }

        cout << postfix << "\n";
    }

    return 0;
}