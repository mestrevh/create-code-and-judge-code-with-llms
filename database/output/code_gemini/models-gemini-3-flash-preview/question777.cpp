/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int patient_code;
    int best_patient = -1;
    int max_timina = -1;

    while (cin >> patient_code && patient_code != 9999) {
        string dna;
        if (!(cin >> dna)) break;

        int current_timina = 0;
        for (char base : dna) {
            if (base == 'T') {
                current_timina++;
            }
        }

        if (current_timina > max_timina) {
            max_timina = current_timina;
            best_patient = patient_code;
        }
    }

    if (best_patient != -1) {
        cout << best_patient << endl;
    }

    return 0;
}