/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int scoreA = 0, scoreB = 0;
    int remA = 5, remB = 5;
    int x;

    // Standard 5 rounds (10 kicks total)
    for (int i = 0; i < 10; ++i) {
        if (!(cin >> x)) break;
        
        if (i % 2 == 0) { // Time Computacao.rar
            remA--;
            if (x == 1) scoreA++;
        } else { // Time Educacao Fisica
            remB--;
            if (x == 1) scoreB++;
        }

        // Check if Computacao won
        if (scoreA > scoreB + remB) {
            cout << "COMPUTACAO.RAR" << endl;
            return 0;
        }
        // Check if Educacao Fisica won
        if (scoreB > scoreA + remA) {
            cout << "EDUCACAO FISICA" << endl;
            return 0;
        }
    }

    // Sudden Death (Batidas Alternadas)
    int kickA, kickB;
    while (cin >> kickA >> kickB) {
        if (kickA == 1) scoreA++;
        if (kickB == 1) scoreB++;

        if (scoreA > scoreB) {
            cout << "COMPUTACAO.RAR" << endl;
            return 0;
        } else if (scoreB > scoreA) {
            cout << "EDUCACAO FISICA" << endl;
            return 0;
        }
    }

    return 0;
}