/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string vote;
    long long countSim = 0;
    long long countOthers = 0;

    while (cin >> vote) {
        for (char &c : vote) {
            c = (char)toupper((unsigned char)c);
        }

        if (vote == "ENCERRAR") {
            break;
        }

        if (vote == "SIM") {
            countSim++;
        } else if (vote == "NAO" || vote == "NULO") {
            countOthers++;
        }
    }

    if (countSim > countOthers) {
        cout << "COM FOGOS" << endl;
    } else {
        cout << "SEM FOGOS" << endl;
    }

    return 0;
}