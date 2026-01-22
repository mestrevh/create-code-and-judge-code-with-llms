/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int voto, alibaba = 0, alcapone = 0, brancos = 0, nulos = 0, total_validos = 0;
    
    while (true) {
        cin >> voto;
        if (voto == -1) break;
        
        if (voto == 83) {
            alibaba++;
        } else if (voto == 93) {
            alcapone++;
        } else if (voto == 0) {
            brancos++;
        } else {
            nulos++;
        }
    }
    
    total_validos = alibaba + alcapone + brancos;
    
    int vencedor = (alibaba > alcapone) ? 83 : 93;
    double perc_alibaba = (static_cast<double>(alibaba) / (total_validos)) * 100;
    double perc_alcapone = (static_cast<double>(alcapone) / (total_validos)) * 100;

    cout << alibaba << endl
         << alcapone << endl
         << brancos << endl
         << nulos << endl
         << vencedor << endl
         << fixed << setprecision(2) << perc_alibaba << endl
         << fixed << setprecision(2) << perc_alcapone << endl;
    
    return 0;
}
