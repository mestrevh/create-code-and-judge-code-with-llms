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

    int D1, D2, M;
    if (cin >> D1 >> D2 >> M) {
        double F = (10.0 * M) / (D1 + D2);
        
        cout << "Scar conseguiu criar uma frustração " << fixed << setprecision(2) << F << " na turma" << endl;
        
        if (F >= 4.0) {
            cout << "Eu matei Mufasa" << endl;
        } else if (F > 2.0) {
            cout << "Consegui lacaios preciosos" << endl;
        } else {
            cout << "Mais um fracasso..." << endl;
        }
    }

    return 0;
}