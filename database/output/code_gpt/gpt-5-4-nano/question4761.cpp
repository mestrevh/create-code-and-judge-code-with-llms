/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    if (!(cin >> n)) return 0;
    
    if (n < 1) {
        cout << "O numero informado eh menor que 1.";
        return 0;
    }
    
    vector<string> ES = {"verde", "azul", "amarelo", "vermelho"};
    vector<string> DS = {"azul", "amarelo", "vermelho", "verde"};
    vector<string> EI = {"amarelo", "vermelho", "verde", "azul"};
    vector<string> DI = {"vermelho", "verde", "azul", "amarelo"};
    
    int idx = int((n - 1) % 4);
    
    cout << "Esquerda superior: " << ES[idx] << "\n";
    cout << "Direita superior: " << DS[idx] << "\n";
    cout << "Esquerda inferior: " << EI[idx] << "\n";
    cout << "Direita inferior: " << DI[idx];
    
    return 0;
}