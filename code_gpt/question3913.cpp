/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int allied[4], enemy[4], reinforcements[4];
    
    for (int i = 0; i < 4; i++)
        cin >> allied[i];
    for (int i = 0; i < 4; i++)
        cin >> enemy[i];
    for (int i = 0; i < 4; i++)
        cin >> reinforcements[i];

    for (int i = 0; i < 4; i++)
        enemy[i] += reinforcements[i];

    int alliedWins = 0, enemyWins = 0;
    for (int i = 0; i < 4; i++) {
        if (allied[i] > enemy[i]) alliedWins++;
        else if (allied[i] < enemy[i]) enemyWins++;
    }

    if (alliedWins > 2)
        cout << "Avancar" << endl;
    else if (enemyWins > 2)
        cout << "Recuar" << endl;
    else
        cout << "Permanecer" << endl;

    return 0;
}
