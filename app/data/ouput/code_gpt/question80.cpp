/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int producao[12][2];
    double custo[2], lucro[2];

    for (int i = 0; i < 12; i++) {
        cin >> producao[i][0] >> producao[i][1];
    }
    cin >> custo[0] >> lucro[0] >> custo[1] >> lucro[1];

    double totalCusto[2] = {0.0, 0.0};
    double totalLucro[2] = {0.0, 0.0};

    for (int i = 0; i < 12; i++) {
        double custoMensalM0 = producao[i][0] * custo[0];
        double lucroMensalM0 = producao[i][0] * lucro[0];
        double custoMensalM1 = producao[i][1] * custo[1];
        double lucroMensalM1 = producao[i][1] * lucro[1];

        totalCusto[0] += custoMensalM0;
        totalLucro[0] += lucroMensalM0;
        totalCusto[1] += custoMensalM1;
        totalLucro[1] += lucroMensalM1;

        cout << fixed << setprecision(2);
        cout << "Motor[0], Mes[" << (i + 1) << "], custo=[" << custoMensalM0 << "], lucro=[" << lucroMensalM0 << "]" << endl;
        cout << "Motor[1], Mes[" << (i + 1) << "], custo=[" << custoMensalM1 << "], lucro=[" << lucroMensalM1 << "]" << endl;
    }

    cout << "Motor[0], anual, custo=[" << totalCusto[0] << "], lucro=[" << totalLucro[0] << "]" << endl;
    cout << "Motor[1], anual, custo=[" << totalCusto[1] << "], lucro=[" << totalLucro[1] << "]" << endl;

    return 0;
}
