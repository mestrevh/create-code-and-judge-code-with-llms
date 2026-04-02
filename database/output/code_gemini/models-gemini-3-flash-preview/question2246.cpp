/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double cache;
    if (!(cin >> cache)) {
        return 0;
    }

    string curso, nome;
    double total = 0.0;

    while (cin >> curso >> nome) {
        if (curso == "CC") {
            total += 5.0;
        } else if (curso == "EC") {
            total += 10.0;
        } else {
            total += 15.0;
        }
    }

    if (total >= cache) {
        cout << "Cebruthius!" << endl;
    } else {
        cout << "Escamou!" << endl;
    }

    return 0;
}