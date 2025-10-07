/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        long long V1, V2, D1, D2;
        cin >> V1 >> V2 >> D1 >> D2;

        long long turns_to_beat_Bezaliel = (V2 + D1 - 1) / D1;
        long long turns_to_beat_Clodes = (V1 + D2 - 1) / D2;
        
        if (turns_to_beat_Bezaliel <= turns_to_beat_Clodes)
            cout << "Bezaliel" << endl;
        else
            cout << "Clodes" << endl;
    }

    return 0;
}
