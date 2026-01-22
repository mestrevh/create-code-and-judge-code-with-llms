/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    string ninjas[8];
    for (int i = 0; i < 8; ++i) {
        getline(cin, ninjas[i]);
    }

    int fights[4][2];
    for (int i = 0; i < 4; ++i) {
        cin >> fights[i][0] >> fights[i][1];
    }

    char winnersQuarter[4];
    for (int i = 0; i < 4; ++i) {
        cin >> winnersQuarter[i];
    }

    char winnersSemi[2];
    for (int i = 0; i < 2; ++i) {
        cin >> winnersSemi[i];
    }

    char finalWinner;
    cin >> finalWinner;

    cout << "Bem vindos ao Exame Chunnin!" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "Quartas de final " << i + 1 << ": " 
             << ninjas[fights[i][winnersQuarter[i] == 'A' ? 0 : 1]] << " x " 
             << ninjas[fights[i][winnersQuarter[i] == 'A' ? 1 : 0]] << endl;
    }

    cout << "Semifinal 1: " 
         << ninjas[fights[0][winnersQuarter[0] == 'A' ? 0 : 1]] << " x " 
         << ninjas[fights[1][winnersQuarter[1] == 'A' ? 0 : 1]] << endl;

    cout << "Semifinal 2: " 
         << ninjas[fights[2][winnersQuarter[2] == 'A' ? 0 : 1]] << " x " 
         << ninjas[fights[3][winnersQuarter[3] == 'A' ? 0 : 1]] << endl;

    cout << "Final: " 
         << ninjas[winnersSemi[0] == 'X' ? fights[0][0] : fights[0][1]] << " x " 
         << ninjas[winnersSemi[1] == 'X' ? fights[1][0] : fights[1][1]] << endl;

    cout << "O grande vencedor e " 
         << ninjas[finalWinner == '#' ? winnersSemi[0] == 'X' ? fights[0][0] : fights[0][1] : winnersSemi[1] == 'Y' ? fights[1][0] : fights[1][1]] << "!" << endl;

    return 0;
}
