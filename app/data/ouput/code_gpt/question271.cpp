/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double raio;
    cin >> raio;
    double area = 3.14159 * (raio / 100) * (raio / 100);
    cout << fixed << setprecision(4) << "Area = " << area << endl;
    return 0;
}
