/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long hp1, hp2;
    if (!(cin >> hp1)) return 0;
    cin >> hp2;

    char type;
    while (true) {
        if (!(cin >> type)) break;
        if (hp1 <= 0 || hp2 <= 0) break;

        char kind;
        cin >> kind;

        int magPow = 0;
        if (type == 'M') {
            if (!(cin >> magPow)) break;
        }

        int attacker = (hp1 > 0 && hp2 > 0) ? 1 : 0;
        attacker = ( ( (long long)0 ) ); 
    }

    cin.clear();
    cin.seekg(0);

    cin >> hp1 >> hp2;

    vector<char> dummy;
    struct Card { char kind; int vulnerable; };
    auto kindToId = [&](char k)->int{
        if (k=='F') return 0;
        if (k=='G') return 1;
        if (k=='T') return 2;
        return -1;
    };

    vector<int> boardKinds1, boardKinds2;
    boardKinds1.clear();
    boardKinds2.clear();

    long long curTurn = 0;
    while (true) {
        if (hp1 <= 0 || hp2 <= 0) break;
        char t;
        if (!(cin >> t)) break;
        char k;
        if (!(cin >> k)) break;

        int v = kindToId(k);
        if (t == 'C') {
            if (curTurn % 2 == 0) boardKinds1.push_back(v);
            else boardKinds2.push_back(v);
        } else if (t == 'M') {
            int power;
            if (!(cin >> power)) break;

            if (curTurn % 2 == 0) {
                vector<int> &def = boardKinds2;
                bool absorbedOrKilled = false;
                auto it = def.end();
                for (auto iter = def.begin(); iter != def.end(); ++iter) {
                    if (*iter == v) { it = iter; break; }
                }
                if (it != def.end()) {
                    def.erase(it);
                    absorbedOrKilled = true;
                }
                if (!absorbedOrKilled) hp2 -= power;
            } else {
                vector<int> &def = boardKinds1;
                bool absorbedOrKilled = false;
                auto it = def.end();
                for (auto iter = def.begin(); iter != def.end(); ++iter) {
                    if (*iter == v) { it = iter; break; }
                }
                if (it != def.end()) {
                    def.erase(it);
                    absorbedOrKilled = true;
                }
                if (!absorbedOrKilled) hp1 -= power;
            }
        } else {
            break;
        }
        curTurn++;
    }

    if (hp2 <= 0) {
        cout << "O jogador 1 ganhou!";
    } else {
        cout << "O jogador 2 ganhou!";
    }
    return 0;
}