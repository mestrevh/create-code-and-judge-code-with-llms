/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double alturaSalto(int I, double A, int D, int P, bool yoshi) {
    if (yoshi) {
        P += 50;
        I += 5;
    }
    return (I * A) / (D + P);
}

int main() {
    int I, D, P;
    double A;
    string S;
    
    cin >> I >> A >> D >> P >> S;
    bool yoshi = (S == "Sim");
    
    double altura = alturaSalto(I, A, D, P, yoshi);
    
    if (altura >= 100) {
        cout << "Voce consegue" << endl;
    } else {
        cout << "Isso e perda de tempo" << endl;
    }
    
    return 0;
}
