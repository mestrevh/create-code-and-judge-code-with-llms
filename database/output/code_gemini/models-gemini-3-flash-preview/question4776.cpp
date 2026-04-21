/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    int X, Y;
    if (!(cin >> N >> X >> Y)) return 0;

    map<int, int> special_clients;
    for (int i = 0; i < Y; ++i) {
        string time_str;
        int z;
        if (cin >> time_str >> z) {
            int hh = stoi(time_str.substr(0, 2));
            int mm = stoi(time_str.substr(3, 2));
            int adj_hh = hh;
            if (adj_hh < 7) adj_hh += 24;
            int total_mins = (adj_hh - 7) * 60 + mm;
            int client_idx = total_mins / 3;
            special_clients[client_idx] = z;
        }
    }

    long long current_total = 0;
    bool winner_found = false;

    for (int i = 1; i <= N; ++i) {
        int client_cans = 0;
        if (special_clients.count(i)) {
            client_cans = special_clients[i];
        } else if (X > 0 && i % X == 0) {
            client_cans = 1;
        }

        current_total += client_cans;
        if (current_total >= 50) {
            int total_mins = i * 3;
            int res_hh = (7 + total_mins / 60) % 24;
            int res_mm = total_mins % 60;
            
            cout << "Quem levou a cesta basica foi o " << i << "* cliente atendido por coragem, as "
                 << setfill('0') << setw(2) << res_hh << ":" << setw(2) << res_mm << ". Que comprou "
                 << client_cans << (client_cans == 1 ? " lata." : " latas.") << endl;
            winner_found = true;
            break;
        }
    }

    if (!winner_found) {
        long long missing = 50 - current_total;
        if (missing == 1) {
            cout << "Ainda nao foram vendidas latas suficientes. Falta 1 lata." << endl;
        } else {
            cout << "Ainda nao foram vendidas latas suficientes. Faltam " << missing << " latas." << endl;
        }
    }

    return 0;
}