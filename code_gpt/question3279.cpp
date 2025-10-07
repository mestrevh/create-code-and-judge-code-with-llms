/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double weight, height;
    cin >> weight >> height;
    double imc = weight / (height * height);
    
    cout << fixed << setprecision(2) << imc << endl;
    
    if (imc < 18 || imc > 25) {
        cout << "atencao" << endl;
    } else {
        cout << "normal" << endl;
    }
    return 0;
}
