/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>

using namespace std;

double CalculaMedia(double n1, double n2, double n3, double n4, double n5) {
    return (n1 + n2 + n3 + n4 + n5) / 5.0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int faltas;
    double n1, n2, n3, n4, n5;

    if (cin >> faltas >> n1 >> n2 >> n3 >> n4 >> n5) {
        double media = CalculaMedia(n1, n2, n3, n4, n5);

        if (faltas <= 5 && media >= 7.0) {
            cout << "APROVADO" << "\n";
        } else {
            cout << "REPROVADO" << "\n";
        }
    }

    return 0;
}