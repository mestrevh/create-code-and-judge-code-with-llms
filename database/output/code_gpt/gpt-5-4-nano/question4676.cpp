/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int SIZE;
    if (!(cin >> SIZE)) return 0;

    vector<long long> a(SIZE, -1);
    int frente = 0;
    int fim = 0;
    int capacidade = SIZE - 1;

    auto imprimir = [&]() {
        for (int i = 0; i < SIZE; i++) {
            if (a[i] == -1) cout << "-";
            else cout << a[i];
            cout << (i + 1 == SIZE ? '\n' : ' ');
        }
    };

    auto cheio = [&]() { return fim == frente - 1 || (frente == 0 && fim == SIZE - 1); };
    auto vazio = [&]() { return fim == frente; };

    string cmd;
    while (cin >> cmd) {
        if (cmd == "F") {
            cout << "Saindo...\n";
            break;
        } else if (cmd == "E") {
            long long x;
            cin >> x;
            if (cheio()) {
                cout << "Fila cheia\n";
            } else {
                a[fim] = x;
                fim = (fim + 1) % SIZE;
                imprimir();
            }
        } else if (cmd == "D") {
            if (vazio()) {
                cout << "Fila vazia\n";
            } else {
                long long val = a[frente];
                a[frente] = -1;
                frente = (frente + 1) % SIZE;
                cout << val << '\n';
                imprimir();
            }
        }
    }

    return 0;
}