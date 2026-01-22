/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int Cv, Ce, Cs, Fv, Fe, Fs;
    cin >> Cv >> Ce >> Cs >> Fv >> Fe >> Fs;

    int pontosC = Cv * 3 + Ce;
    int pontosF = Fv * 3 + Fe;

    if (pontosC > pontosF || (pontosC == pontosF && Cs > Fs)) {
        cout << 'C' << endl;
    } else if (pontosF > pontosC || (pontosC == pontosF && Fs > Cs)) {
        cout << 'F' << endl;
    } else {
        cout << '=' << endl;
    }
    
    return 0;
}
