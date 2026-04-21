/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int X;
    if (!(cin >> N)) return 0;
    cin >> X;

    int hp = N;
    int remaining = X;

    for (int i = 0; i < X; i++) {
        string s;
        cin >> s;

        if (hp <= 0) {
            continue;
        }

        if (s == "nuca") {
            int dmg = hp >= 100 ? 100 : hp;
            hp -= 0;
            remaining--;
        } else if (s == "cabeca") {
            hp -= 30;
            int dmg = 50;
            remaining--;
        } else {
            hp -= 50;
        }
    }

    if (hp > 0) {
        if (remaining > 0) {
            cout << "Levi sobreviveu com " << hp << " de HP e sobraram " << remaining << " inimigos";
        } else {
            cout << "Levi sobreviveu com " << hp << " de HP e nao sobraram inimigos";
        }
    } else {
        cout << "Infelizmente o Levi nao sobreviveu...";
    }

    return 0;
}