/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;
    vector<string> car_participants(N);
    for (int i = 0; i < N; ++i) {
        cin >> car_participants[i];
    }
    sort(car_participants.begin(), car_participants.end());

    int M;
    if (!(cin >> M)) return 0;
    vector<string> moto_participants(M);
    for (int i = 0; i < M; ++i) {
        cin >> moto_participants[i];
    }
    sort(moto_participants.begin(), moto_participants.end());

    int n1, n2;
    if (!(cin >> n1 >> n2)) return 0;

    string winner_car = car_participants[n1 - 1];
    string winner_moto = moto_participants[n2 - 1];

    if (winner_car == winner_moto) {
        cout << "Quem ganhou tudo hoje foi " << winner_car << "\n";
    } else {
        cout << "Quem ganhou o carro foi: " << winner_car << "\n";
        cout << "Quem ganhou a moto foi: " << winner_moto << "\n";
    }

    return 0;
}