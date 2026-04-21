/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long hp;
    int x;
    if (!(cin >> hp >> x)) {
        return 0;
    }

    int remaining_enemies = x;
    bool dead = (hp <= 0);

    for (int i = 0; i < x; ++i) {
        string s;
        cin >> s;

        if (!dead) {
            if (s == "nuca") {
                remaining_enemies--;
            } else if (s == "cabeca") {
                hp -= 30;
            } else {
                hp -= 50;
            }

            if (hp <= 0) {
                dead = true;
            }
        }
    }

    if (dead) {
        cout << "Infelizmente o Levi nao sobreviveu..." << endl;
    } else {
        cout << "Levi sobreviveu com " << hp << " de HP e ";
        if (remaining_enemies > 0) {
            cout << "sobraram " << remaining_enemies << " inimigos" << endl;
        } else {
            cout << "nao sobraram inimigos" << endl;
        }
    }

    return 0;
}