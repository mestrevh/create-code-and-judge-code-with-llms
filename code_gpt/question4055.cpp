/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int hp_player, attack_player, hp_rathound, attack_rathound;
    cin >> hp_player >> attack_player >> hp_rathound >> attack_rathound;

    if (hp_player * attack_player > hp_rathound * attack_rathound) {
        cout << "Matei um rathound" << endl;
    } else {
        cout << "Fugi de um rathound" << endl;
    }

    return 0;
}
