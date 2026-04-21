/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<double> notes(5);
    for (int i = 0; i < 5; ++i) {
        if (!(cin >> notes[i])) break;
    }

    sort(notes.begin(), notes.end());

    double sum = notes[1] + notes[2] + notes[3];

    cout << fixed << setprecision(1) << sum << endl;

    return 0;
}