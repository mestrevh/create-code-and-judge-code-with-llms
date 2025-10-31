/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int creditosPagos;
    cin >> creditosPagos;
    
    int totalCreditos = 260;
    int creditosPorSemestre = 24;
    
    int creditosRestantes = totalCreditos - creditosPagos;
    int semestresNecessarios = (creditosRestantes + creditosPorSemestre - 1) / creditosPorSemestre;
    
    cout << semestresNecessarios << endl;

    return 0;
}
