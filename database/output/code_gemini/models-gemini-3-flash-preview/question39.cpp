/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double n1, n2, n3;
    if (!(cin >> n1 >> n2 >> n3)) return 0;

    double average = (n1 + n2 + n3) / 3.0;

    if (average >= 7.0) {
        cout << "aprovado" << endl;
    } else if (average < 3.0) {
        cout << "reprovado" << endl;
    } else {
        cout << "prova final" << endl;
    }

    return 0;
}