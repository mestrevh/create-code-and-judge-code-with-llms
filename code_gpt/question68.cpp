/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Boi {
    int id;
    double peso;
};

int main() {
    int n;
    cin >> n;
    vector<Boi> bois(n);
    for (int i = 0; i < n; ++i) {
        cin >> bois[i].id >> bois[i].peso;
    }
    
    Boi maisGordo = bois[0], maisMagro = bois[0];
    for (int i = 1; i < n; ++i) {
        if (bois[i].peso > maisGordo.peso) maisGordo = bois[i];
        if (bois[i].peso < maisMagro.peso) maisMagro = bois[i];
    }
    
    cout << fixed << setprecision(2);
    cout << "Gordo: id: " << maisGordo.id << " peso: " << maisGordo.peso << "Kg" << endl;
    cout << "Magro: id: " << maisMagro.id << " peso: " << maisMagro.peso << "Kg" << endl;
    
    return 0;
}
