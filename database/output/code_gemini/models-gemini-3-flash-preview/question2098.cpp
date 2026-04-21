/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    double T;
    if (!(cin >> N >> T)) return 0;

    vector<int> houses(N);
    for (int i = 0; i < N; ++i) {
        cin >> houses[i];
    }

    int found_house = -1;
    bool found = false;

    for (int i = 0; i < N; ++i) {
        double s;
        cin >> s;
        if (!found && abs(s - T) < 1e-8) {
            found_house = houses[i];
            found = true;
        }
    }

    if (found) {
        cout << "Cinderela mora na casa " << found_house << "!" << endl;
    } else {
        cout << "Nenhuma das jovens e a moca do baile." << endl;
    }

    return 0;
}