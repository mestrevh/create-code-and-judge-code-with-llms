/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        double X;
        cin >> X;
        int dias = 0;
        while (X > 1.0) {
            X /= 2;
            dias++;
        }
        cout << dias << " dias" << endl;
    }
    return 0;
}
