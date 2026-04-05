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

    long long codigo;
    while (true) {
        cout << "Informe o codigo do aluno: (0 para encerrar o programa)" << endl;
        if (!(cin >> codigo) || codigo == 0) {
            break;
        }

        double n1, n2, n3;
        cout << "Informe a primeira nota do aluno:" << endl;
        if (!(cin >> n1)) break;
        cout << "Informe a segunda nota do aluno:" << endl;
        if (!(cin >> n2)) break;
        cout << "Informe a terceira nota do aluno:" << endl;
        if (!(cin >> n3)) break;

        double media = (n1 + n2 + n3) / 3.0;
        
        cout << "Media do aluno: " << media << endl;
    }

    return 0;
}