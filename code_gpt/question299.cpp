/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int cGoals = 0, edfGoals = 0;
    int cPenalties[5], edfPenalties[5];
    
    for (int i = 0; i < 5; ++i) {
        cin >> cPenalties[i];
        cin >> edfPenalties[i];
        if (cPenalties[i] == 1) cGoals++;
        if (edfPenalties[i] == 1) edfGoals++;
        
        if (cGoals > edfGoals + (4 - i)) {
            cout << "COMPUTACAO.RAR" << endl;
            return 0;
        }
        if (edfGoals > cGoals + (4 - i)) {
            cout << "EDUCACAO FISICA" << endl;
            return 0;
        }
    }
    
    int i = 5;
    while (true) {
        int cNext, edfNext;
        cin >> cNext;
        if (cNext == 1) cGoals++;
        
        if (edfGoals > cGoals) {
            cout << "EDUCACAO FISICA" << endl;
            return 0;
        }
        
        if (edfNext == 1) edfGoals++;
        
        if (cGoals > edfGoals) {
            cout << "COMPUTACAO.RAR" << endl;
            return 0;
        }
        
        i++;
    }
}
