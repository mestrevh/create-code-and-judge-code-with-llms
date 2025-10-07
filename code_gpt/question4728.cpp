/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

string inverterFrases(const string& frase) {
    stack<char> pilha;
    string resultado;
    
    for (char c : frase) {
        if (c != ' ') {
            pilha.push(c);
        } else {
            while (!pilha.empty()) {
                resultado += pilha.top();
                pilha.pop();
            }
            resultado += ' ';
        }
    }
    
    while (!pilha.empty()) {
        resultado += pilha.top();
        pilha.pop();
    }
    
    return resultado;
}

int main() {
    string frase;
    getline(cin, frase);
    
    cout << inverterFrases(frase) << endl;

    return 0;
}
