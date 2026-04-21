/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count = 0;
    double distance;
    for (int i = 0; i < 7; ++i) {
        if (cin >> distance) {
            if (distance >= 8.0) {
                count++;
            }
        }
    }

    if (count >= 5) {
        cout << "Desempenho otimo" << endl;
    } else if (count >= 3) {
        cout << "Desempenho razoavel" << endl;
    } else {
        cout << "Desempenho ruim" << endl;
    }

    return 0;
}