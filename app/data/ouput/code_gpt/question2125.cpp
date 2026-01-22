/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

double chanceDemogorgon(int hour, int blood) {
    if (blood < 0) return -1;
    if (hour < 5 || hour > 12) return -1;

    if (hour == 5) return 5;

    double previousChance = chanceDemogorgon(hour - 1, blood);
    if (previousChance < 0) return -1;

    if (hour >= 6 && hour <= 15) {
        if (hour % 2 == 0) return previousChance + blood / 2.0;
        else return previousChance + static_cast<int>(previousChance) % 7;
    } else {
        if (hour % 2 == 0) return previousChance + blood;
        else return previousChance + static_cast<int>(previousChance) % 10;
    }
}

int main() {
    string period;
    int hour, blood;

    cin >> hour >> period;
    cin >> blood;

    if (period == "pm" && hour != 12) hour += 12;
    if (period == "am" && hour == 12) hour = 0;

    double chance = chanceDemogorgon(hour, blood);

    if (chance < 0) {
        cout << "Dados Invalidos." << endl;
    } else {
        cout << fixed << setprecision(1);
        cout << "A chance de aparecimento de Demogorgon e de " << chance << "%." << endl;
        if (chance >= 100) {
            cout << "Ou seja, nao olhe para tras." << endl;
        }
    }

    return 0;
}
