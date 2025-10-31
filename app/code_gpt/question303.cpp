/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int tempo;
    int velocidade;
    
    cin >> tempo >> velocidade;
    
    double distancia = tempo * velocidade;
    double litros = distancia / 12.0;
    
    cout << fixed << setprecision(3) << litros << endl;
    
    return 0;
}
