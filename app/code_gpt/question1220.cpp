/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    map<char, pair<double, int>> teams; // {team: {total_power, count}}

    for (int i = 0; i < N; ++i) {
        char team;
        double power;
        cin >> team >> power;
        teams[team].first += power;
        teams[team].second++;
    }

    char best_team = 'A';
    double best_average = -1;

    for (const auto& [team, data] : teams) {
        double average = data.first / data.second;
        if (average > best_average || (average == best_average && team < best_team)) {
            best_average = average;
            best_team = team;
        }
    }

    cout << "A equipe escolhida foi a " << best_team << ", com media de: " << fixed << setprecision(2) << best_average << endl;
    return 0;
}
