/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double R;
    const double pi = 3.1416;
    
    cout << "Digite o raio da esfera:" << endl;
    cin >> R;
    
    double area = 4 * pi * R * R;
    double volume = (4 * pi * R * R * R) / 3;
    
    cout << fixed << setprecision(3);
    cout << "A area da superficie esferica e igual a " << area << endl;
    cout << "O volume da esfera e igual a " << volume << endl;

    return 0;
}
