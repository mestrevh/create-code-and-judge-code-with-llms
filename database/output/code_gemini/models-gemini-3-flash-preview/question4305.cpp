/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double x, y;
    char l;
    int n;

    if (!(cin >> x >> y >> l >> n)) return 0;

    bool input_valid = true;
    if (x < 0.0 || x >= 24.0) input_valid = false;
    else if (y < 0.0 || y >= 24.0) input_valid = false;
    else if (x >= y) input_valid = false;
    else if (l != 'A' && l != 'B') input_valid = false;
    else if (n <= 0) input_valid = false;

    if (!input_valid) {
        cout << "Entrada Invalida" << endl;
    } else {
        double duration = y - x;
        double limit = (l == 'A' ? 1.0 : 0.75);
        int capacity = 5;

        // If duration is 50% or more than the required minimum time (prazo)
        if (duration >= (limit * 1.5) - 1e-9) {
            capacity = 9;
        }

        // Rules check
        if (duration > limit + 1e-9 && n <= capacity) {
            cout << "O uninho faz a boa, obrigado querida mae line" << endl;
        } else {
            cout << "Infelizmente o uninho nao tanka, rodamos!" << endl;
        }
    }

    return 0;
}