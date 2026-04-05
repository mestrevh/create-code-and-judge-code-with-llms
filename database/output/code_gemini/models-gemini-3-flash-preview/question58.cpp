/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Country {
    int id;
    int gold;
    int silver;
    int bronze;

    Country() : id(0), gold(0), silver(0), bronze(0) {}
};

bool compareCountries(const Country& a, const Country& b) {
    if (a.gold != b.gold) {
        return a.gold > b.gold;
    }
    if (a.silver != b.silver) {
        return a.silver > b.silver;
    }
    if (a.bronze != b.bronze) {
        return a.bronze > b.bronze;
    }
    return a.id < b.id;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<Country> countries(N);
    for (int i = 0; i < N; ++i) {
        countries[i].id = i + 1;
        countries[i].gold = 0;
        countries[i].silver = 0;
        countries[i].bronze = 0;
    }

    for (int i = 0; i < M; ++i) {
        int o, p, b;
        if (cin >> o >> p >> b) {
            countries[o - 1].gold++;
            countries[p - 1].silver++;
            countries[b - 1].bronze++;
        }
    }

    sort(countries.begin(), countries.end(), compareCountries);

    for (int i = 0; i < N; ++i) {
        cout << countries[i].id << "\n";
    }

    return 0;
}