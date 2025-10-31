/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int interfaceGrafica, inteligenciaArtificial, encapsulamento, identacao, structs;
    cin >> interfaceGrafica >> inteligenciaArtificial >> encapsulamento >> identacao >> structs;

    cout << "Trabalho aborda Interface Grafica? (0 - Nao 1 - Sim)" << endl;
    cout << "Trabalho aborda Inteligencia Artificial? (0 - Nao 1 - Sim)" << endl;
    cout << "Trabalho aborda Encapsulamento? (0 - Nao 1 - Sim)" << endl;
    cout << "Trabalho aborda Indentacao? (0 - Nao 1 - Sim)" << endl;
    cout << "Trabalho aborda Structs? (0 - Nao 1 - Sim)" << endl;

    if ((interfaceGrafica || inteligenciaArtificial) && encapsulamento && identacao && structs) {
        cout << "Seu trabalho sera avaliado." << endl;
    } else {
        cout << "Seu trabalho nao sera avaliado, nota 0." << endl;
    }

    return 0;
}
