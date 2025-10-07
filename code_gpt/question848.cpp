/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double R;
    const double pi = 3.1416;
    
    cin >> R;
    
    double area = 4 * pi * R * R;
    double volume = (4 * pi * R * R * R) / 3;
    
    cout << fixed << setprecision(2) << area << endl;
    cout << fixed << setprecision(2) << volume << endl;
    
    return 0;
}
