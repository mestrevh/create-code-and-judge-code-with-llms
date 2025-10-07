/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int x;
    cin >> x;

    int total_tacas = 0;
    for (int i = 0; i < x; ++i) {
        vector<int> notas;
        int nota;
        while (cin >> nota && nota != 0) {
            notas.push_back(nota);
        }
        if (!notas.empty()) {
            total_tacas += accumulate(notas.begin(), notas.end(), 0) / notas.size();
        }
    }

    cout << "Elas beberam " << total_tacas << " taças!" << endl;

    return 0;
}
