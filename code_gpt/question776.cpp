/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int periodo(int ano, const string& era) {
    int anoReal = (era == "aC") ? -ano : ano;
    if (anoReal < -4000) return 1;
    if (anoReal >= -3999 && anoReal <= 476) return 2;
    if (anoReal >= 477 && anoReal <= 1789) return 3;
    return 4;
}

int main() {
    int ano;
    string era;
    int maxPeriodo = 0;

    for (int i = 0; i < 3; ++i) {
        cin >> ano >> era;
        int p = periodo(ano, era);
        maxPeriodo = max(maxPeriodo, p);
    }

    cout << maxPeriodo << endl;
    return 0;
}
