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

    double sum = 0.0;
    double value;
    int count = 100;

    for (int i = 0; i < count; ++i) {
        cout << "Digite um numero:" << "\n";
        if (cin >> value) {
            sum += value;
        }
    }

    double average = sum / 100.0;
    
    cout << "Media dos numeros: " << setprecision(17) << average << endl;

    return 0;
}