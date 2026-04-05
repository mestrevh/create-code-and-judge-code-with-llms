/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, long long> seats;
    seats.reserve(64);

    for (int i = 0; i < 37; i++) {
        int flight;
        long long available;
        if (!(cin >> flight >> available)) return 0;
        seats[flight] = available;
    }

    cout << "Digite o numero do voo e a quantidade de lugares disponiveis:\n";
    cout << "Digite o pedido de reserva:\n";

    int pedido;
    while (cin >> pedido) {
        if (pedido == 9999) break;

        auto it = seats.find(pedido);
        if (it == seats.end()) {
            cout << "Voo " << pedido << " INDISPONIVEL\n";
        } else if (it->second > 0) {
            cout << "Voo " << pedido << " DISPONIVEL\n";
            it->second--;
        } else {
            cout << "Voo " << pedido << " INDISPONIVEL\n";
        }

        cout << "Digite o pedido de reserva:\n";
    }

    return 0;
}