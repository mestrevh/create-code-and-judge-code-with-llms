/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

string CalculaMedia(double n1, double n2, double n3, double n4, double n5) {
    double media = (n1 + n2 + n3 + n4 + n5) / 5.0;
    return (media >= 7.0) ? "APROVADO" : "REPROVADO";
}

int main() {
    int faltas;
    double n1, n2, n3, n4, n5;
    cin >> faltas >> n1 >> n2 >> n3 >> n4 >> n5;
    
    if (faltas <= 5) {
        cout << CalculaMedia(n1, n2, n3, n4, n5) << endl;
    } else {
        cout << "REPROVADO" << endl;
    }

    return 0;
}
