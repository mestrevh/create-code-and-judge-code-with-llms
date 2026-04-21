/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

string AnalisarSituacao(double n1, double n2, double n3, double n4) {
    double media = (n1 * 1.0 + n2 * 2.0 + n3 * 3.0 + n4 * 4.0) / 10.0;
    if (media >= 9.0) {
        return "aprovado com louvor";
    } else if (media >= 7.0) {
        return "aprovado";
    } else if (media >= 3.0) {
        return "prova final";
    } else {
        return "reprovado";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double n1, n2, n3, n4;
    if (cin >> n1 >> n2 >> n3 >> n4) {
        cout << AnalisarSituacao(n1, n2, n3, n4) << endl;
    }

    return 0;
}