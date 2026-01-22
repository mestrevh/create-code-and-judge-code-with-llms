/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

double calcularQ1(double R, double t) {
    return t / (R / 100);
}

double calcularQ2(double Q1, double t) {
    return Q1 - t;
}

int main() {
    double R, t;
    
    while (true) {
        cin >> R >> t;
        if (R >= 100) break;
        
        double Q1 = calcularQ1(R, t);
        double Q2 = calcularQ2(Q1, t);
        
        Q1 /= 4; // convertendo J para calorias
        Q2 /= 4; // convertendo J para calorias
        
        cout << fixed << setprecision(2);
        cout << "Q1 = " << Q1 << " cal" << endl;
        cout << "Q2 = " << Q2 << " cal" << endl;
    }
    
    return 0;
}
