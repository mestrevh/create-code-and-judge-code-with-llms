/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double quantl, quantf, tameq, numb;
    
    if (cin >> quantl >> quantf >> tameq >> numb) {
        double eficiencia = (quantl / quantf) / tameq - 4.2 * numb;
        cout << fixed << setprecision(1) << eficiencia << endl;
    }

    return 0;
}