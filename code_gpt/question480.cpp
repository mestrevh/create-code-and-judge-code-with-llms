/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string sexo, servico;
    int corteH = 0, barbaH = 0;
    double faturamentoTotal = 0.0;

    while (true) {
        cin >> sexo;
        if (sexo != "M" && sexo != "F" && sexo != "m" && sexo != "f") break;
        
        cin >> servico;
        transform(servico.begin(), servico.end(), servico.begin(), ::tolower);

        if (sexo == "M" || sexo == "m") {
            if (servico == "corte") {
                corteH++;
                faturamentoTotal += 25.0;
            } else if (servico == "barba") {
                barbaH++;
                faturamentoTotal += 15.0;
            }
        } else if (sexo == "F" || sexo == "f") {
            if (servico == "maquiagem") {
                faturamentoTotal += 70.0;
            } else if (servico == "penteado") {
                faturamentoTotal += 50.0;
            } else if (servico == "corte") {
                faturamentoTotal += 40.0;
            }
        }
    }

    string resultado;
    if (corteH > barbaH) {
        resultado = "CORTE";
    } else if (barbaH > corteH) {
        resultado = "BARBA";
    } else {
        resultado = "AMBOS";
    }

    cout << resultado << endl;
    cout << fixed << setprecision(2) << faturamentoTotal << endl;

    return 0;
}
