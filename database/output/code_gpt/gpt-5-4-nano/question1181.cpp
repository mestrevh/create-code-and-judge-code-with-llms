/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    int febre = 0, tempNormal = 0;
    int pressOtima = 0, pressNormal = 0, pressLimitrofe = 0, hipertensao = 0;
    int pressSistolicaCnt = 0, observacao = 0;

    for (int i = 0; i < n; i++) {
        int temp, sys, dia;
        cin >> temp >> sys >> dia;

        bool isFebre = temp > 38;
        if (isFebre) febre++;
        else tempNormal++;

        if (sys <= 119) {
            pressOtima++;
            if (sys >= 120) pressSistolicaCnt++;
        } else if (sys <= 129) {
            pressNormal++;
        } else if (sys <= 139) {
            pressLimitrofe++;
        } else {
            hipertensao++;
        }

        if (dia <= 79) {
            pressSistolicaCnt++;
        }

        if (isFebre && (sys >= 140 || dia >= 90)) observacao++;
    }

    cout << "febre: " << febre << "\n";
    cout << "temperatura normal: " << tempNormal << "\n";
    cout << "pressao otima: " << pressOtima << "\n";
    cout << "pressao normal: " << pressNormal << "\n";
    cout << "pressao limitrofe: " << pressLimitrofe << "\n";
    cout << "hipertensao: " << hipertensao << "\n";
    cout << "pressao sistolica: " << pressSistolicaCnt << "\n";
    cout << "observacao: " << observacao << "\n";

    return 0;
}