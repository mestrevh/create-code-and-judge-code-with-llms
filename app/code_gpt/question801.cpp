/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

double calcularMediaPonderada(double n1, double n2, double n3, double n4) {
    return (n1 * 1 + n2 * 2 + n3 * 3 + n4 * 4) / 10;
}

string AnalisarSituacao(double n1, double n2, double n3, double n4) {
    double media = calcularMediaPonderada(n1, n2, n3, n4);
    if (media >= 9) return "aprovado com louvor";
    if (media >= 7) return "aprovado";
    if (media < 3) return "reprovado";
    return "prova final";
}

int main() {
    double n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;
    cout << AnalisarSituacao(n1, n2, n3, n4) << endl;
    return 0;
}
