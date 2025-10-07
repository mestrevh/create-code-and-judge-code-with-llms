/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    long long n, V1, V2, D1, D2;
    cin >> n;
    while (n--) {
        cin >> V1 >> V2 >> D1 >> D2;
        long long turnsClodes = (V2 + D1 - 1) / D1;
        long long turnsBezaliel = (V1 + D2 - 1) / D2;
        
        if (turnsClodes <= turnsBezaliel) {
            cout << "Clodes" << endl;
        } else {
            long long maxAttacks = 0;
            while (true) {
                long long potentialDamage = min((maxAttacks + 1) * 50 + D1, V1);
                long long turnsClodesAfterBoost = (V2 + potentialDamage - 1) / potentialDamage;
                long long turnsBezalielAfterBoost = (V1 + D2 - 1) / D2;
                
                if (turnsClodesAfterBoost <= turnsBezalielAfterBoost) {
                    cout << "Clodes" << endl;
                    break;
                }
                maxAttacks++;
            }
        }
    }
    return 0;
}
