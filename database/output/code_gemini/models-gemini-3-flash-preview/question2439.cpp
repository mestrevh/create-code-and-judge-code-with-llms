/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long D, G, P;
    if (!(cin >> D >> G >> P)) return 0;

    long long current_pos = 0;
    long long current_gas = G;
    long long refills = 0;
    bool possible = true;

    for (long long i = 1; i <= P; ++i) {
        if (i > D / 20 + 1) break;
        long long station_pos = i * 20;
        if (station_pos > D) break;

        long long distance_to_travel = station_pos - current_pos;
        if (current_gas < distance_to_travel) {
            possible = false;
            break;
        }

        current_gas -= distance_to_travel;
        current_gas += 15;
        current_pos = station_pos;
        refills++;
    }

    if (possible) {
        long long final_distance = D - current_pos;
        if (current_gas < final_distance) {
            possible = false;
        }
    }

    if (possible) {
        cout << "Finalmente cheguei, tive que abastecer em " << refills << " postos" << endl;
    } else {
        cout << "Xii... Acho que nao vai dar pra te ver, Jasmine" << endl;
    }

    return 0;
}