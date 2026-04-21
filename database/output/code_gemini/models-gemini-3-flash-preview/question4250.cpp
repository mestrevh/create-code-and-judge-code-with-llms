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

    double R;
    if (!(cin >> R)) return 0;

    const double PI = 3.1416;
    double area = 4.0 * PI * R * R;
    double volume = (4.0 * PI * R * R * R) / 3.0;

    cout << "Digite o raio da esfera:" << "\n";
    cout << fixed << setprecision(3);
    cout << "A area da superficie esferica e igual a " << area << "\n";
    cout << "O volume da esfera e igual a " << volume << endl;

    return 0;
}