/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long D, G;
    int P;
    if (!(cin >> D >> G >> P)) return 0;

    long long fuel = G;
    int used = 0;
    for (int i = 1; i <= P; i++) {
        long long pos = 20LL * i;
        if (fuel < pos) break;
        fuel -= pos;
        used++;
        fuel += 15;
    }

    if (used == 0) {
        if (fuel >= D) {
            cout << "Finalmente cheguei, tive que abastecer em " << used << " postos";
        } else {
            cout << "Xii... Acho que nao vai dar pra te ver, Jasmine";
        }
        return 0;
    }

    if (fuel >= D) {
        cout << "Finalmente cheguei, tive que abastecer em " << used << " postos";
    } else {
        cout << "Xii... Acho que nao vai dar pra te ver, Jasmine";
    }

    return 0;
}