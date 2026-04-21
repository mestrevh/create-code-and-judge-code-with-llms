/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int id;
    double total_kwh_acc = 0;
    double sum_1_2 = 0;
    int count_1_2 = 0;

    while (true) {
        cout << "Digite o numero do consumidor:\n";
        if (!(cin >> id) || id == 0) {
            break;
        }

        double kwh;
        cout << "Digite a quantidade de KWh consumidos:\n";
        cin >> kwh;

        int type;
        cout << "Digite o tipo de consumidor:\n";
        cin >> type;

        double price = 0.0;
        if (type == 1) {
            price = 0.3;
        } else if (type == 2) {
            price = 0.5;
        } else if (type == 3) {
            price = 0.7;
        }

        double cost = kwh * price;
        total_kwh_acc += kwh;

        if (type == 1 || type == 2) {
            sum_1_2 += kwh;
            count_1_2++;
        }

        cout << "Custo total para o consumidor " << id << ": R$ " << fixed << setprecision(2) << cost << "\n";
        cout << "Total de consumo acumulado: " << (long long)total_kwh_acc << " Kwh\n";

        double avg = 0.0;
        if (count_1_2 > 0) {
            avg = sum_1_2 / (double)count_1_2;
        }
        cout << "Media de consumo dos tipos 1 e 2: " << fixed << setprecision(1) << avg << " KWh\n";
    }

    return 0;
}