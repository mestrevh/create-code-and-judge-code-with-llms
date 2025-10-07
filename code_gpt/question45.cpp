/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int horas, minutos;
    cin >> horas >> minutos;

    string periodo = "am";
    if (horas == 0) {
        horas = 12;
    } else if (horas == 12) {
        periodo = "pm";
    } else if (horas > 12) {
        horas -= 12;
        periodo = "pm";
    }
    
    cout << setw(2) << setfill('0') << horas << endl;
    cout << setw(2) << setfill('0') << minutos << endl;
    cout << periodo << endl;

    return 0;
}
