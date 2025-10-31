/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string nome;
    while (true) {
        getline(cin, nome);
        if (nome == "FIM") break;

        int num_midia;
        sscanf(nome.c_str(), "%[^ ] %d", &nome[0], &num_midia);
        
        double custo_total = 0;
        for (int i = 0; i < num_midia; ++i) {
            string midia;
            getline(cin, midia);
            if (midia == "internet") {
                custo_total += 3000;
            } else if (midia == "revista") {
                custo_total += 750;
            } else if (midia == "outdoor") {
                custo_total += 1500;
            } else if (midia == "radio") {
                string tipo_radio;
                getline(cin, tipo_radio);
                if (tipo_radio == "fm") {
                    custo_total += 500;
                } else {
                    custo_total += 300;
                }
            } else if (midia == "tv") {
                int horario;
                cin >> horario;
                cin.ignore();
                if (horario <= 20) {
                    custo_total += 1200;
                } else {
                    custo_total += 2000;
                }
            }
        }
        cout << fixed << setprecision(2) << nome << ": " << custo_total << endl;
    }
    return 0;
}
