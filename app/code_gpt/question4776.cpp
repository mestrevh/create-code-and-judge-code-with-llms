/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<pair<string, int>> clients(Y);
    for (int i = 0; i < Y; i++) {
        cin >> clients[i].first >> clients[i].second;
    }

    int num_one_can_clients = (X == 0) ? 0 : N / X;
    int total_clients = num_one_can_clients + Y;

    if (total_clients < 50) {
        cout << "Ainda nao foram vendidas latas suficientes. Faltam " << (50 - total_clients) << " latas." << endl;
        return 0;
    }

    int winner_index = 49; // 0-based index for the 50th customer
    string winner_time;
    int winner_cans;

    if (Y > 0) {
        winner_time = clients[winner_index - num_one_can_clients].first;
        winner_cans = clients[winner_index - num_one_can_clients].second;
    } else {
        winner_time = (num_one_can_clients * 3 < 60) ? "07:" + to_string(num_one_can_clients * 3) : 
            to_string(7 + (num_one_can_clients * 3) / 60) + ":" + to_string((num_one_can_clients * 3) % 60);
        winner_cans = 1;
    }

    cout << "Quem levou a cesta basica foi o 50* cliente atendido por coragem, as " << winner_time << ". Que comprou " << winner_cans << " latas." << endl;

    return 0;
}
