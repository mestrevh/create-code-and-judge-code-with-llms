/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int D, VF, VG;
    while (true) {
        cin >> D >> VF >> VG;
        if (D == -1 && VF == -1 && VG == -1) break;
        
        double timeFugitive = 12.0 / VF;
        double timeGuard = (D * 12.0) / (VG * (VG - VF));
        
        if (timeGuard < timeFugitive) {
            cout << "S" << endl;
        } else {
            cout << "N" << endl;
        }
    }
    return 0;
}
