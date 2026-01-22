/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();
    
    vector<double> pesos;
    vector<double> gastos;
    
    for (int i = 0; i < N; ++i) {
        double V;
        getline(cin, to_string(V)); // Lê o valor gasto
        string frutas;
        getline(cin, frutas); // Lê os nomes das frutas
        
        double kg = count(frutas.begin(), frutas.end(), ' ') + 1; // Contar quantas frutas foram compradas
        pesos.push_back(kg);
        gastos.push_back(V);
        
        cout << "dia " << (i + 1) << ": " << kg << " kg\n";
    }
    
    double mediaPeso = 0, mediaGasto = 0;
    for (int i = 0; i < N; ++i) {
        mediaPeso += pesos[i];
        mediaGasto += gastos[i];
    }
    
    mediaPeso /= N;
    mediaGasto /= N;
    
    cout << fixed << setprecision(2);
    cout << mediaPeso << " kg por dia\n";
    cout << "R$ " << mediaGasto << " por dia\n";
    
    return 0;
}
