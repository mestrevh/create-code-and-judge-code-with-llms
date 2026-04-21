/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int interfaceGrafica, inteligenciaArtificial, encapsulamento, indentacao, structs;
    if (!(cin >> interfaceGrafica >> inteligenciaArtificial >> encapsulamento >> indentacao >> structs)) return 0;

    bool interfaceOuAI = (interfaceGrafica == 1) || (inteligenciaArtificial == 1);
    bool ok = interfaceOuAI && encapsulamento == 1 && indentacao == 1 && structs == 1;

    cout << "Trabalho aborda Interface Grafica? (0 - Nao 1 - Sim)\n";
    cout << "Trabalho aborda Inteligencia Artificial? (0 - Nao 1 - Sim)\n";
    cout << "Trabalho aborda Encapsulamento? (0 - Nao 1 - Sim)\n";
    cout << "Trabalho aborda Indentacao? (0 - Nao 1 - Sim)\n";
    cout << "Trabalho aborda Structs? (0 - Nao 1 - Sim)\n";
    if (ok) cout << "Seu trabalho sera avaliado.";
    else cout << "Seu trabalho nao sera avaliado, nota 0.";
    return 0;
}