/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int numeroConsumidor, tipoConsumidor;
    double kWhConsumidos, custoTotal;
    double totalResidencial = 0, totalComercial = 0, totalIndustrial = 0;
    double somaTipos12 = 0;
    int contTipos12 = 0;

    while (true) {
        cout << "Digite o numero do consumidor:" << endl;
        cin >> numeroConsumidor;
        if (numeroConsumidor == 0) break;

        cout << "Digite a quantidade de KWh consumidos:" << endl;
        cin >> kWhConsumidos;

        cout << "Digite o tipo de consumidor:" << endl;
        cin >> tipoConsumidor;

        switch (tipoConsumidor) {
            case 1:
                custoTotal = kWhConsumidos * 0.3;
                totalResidencial += kWhConsumidos;
                somaTipos12 += kWhConsumidos;
                contTipos12++;
                break;
            case 2:
                custoTotal = kWhConsumidos * 0.5;
                totalComercial += kWhConsumidos;
                somaTipos12 += kWhConsumidos;
                contTipos12++;
                break;
            case 3:
                custoTotal = kWhConsumidos * 0.7;
                totalIndustrial += kWhConsumidos;
                break;
            default:
                continue;
        }

        cout << fixed << setprecision(2);
        cout << "Custo total para o consumidor " << numeroConsumidor << ": R$ " << custoTotal << endl;

        double totalConsumo = totalResidencial + totalComercial + totalIndustrial;
        cout << "Total de consumo acumulado: " << totalConsumo << " Kwh" << endl;

        double mediaTipos12 = (contTipos12 > 0) ? (somaTipos12 / contTipos12) : 0;
        cout << fixed << setprecision(1);
        cout << "Media de consumo dos tipos 1 e 2: " << mediaTipos12 << " KWh" << endl;
    }
    return 0;
}
