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

    double n1, n2;
    if (!(cin >> n1 >> n2)) return 0;

    char op;
    if (!(cin >> op)) return 0;

    cout << fixed << setprecision(3);

    double current_res = n1;
    bool success = false;

    if (op == '+') {
        current_res = n1 + n2;
        success = true;
    } else if (op == '-') {
        current_res = n1 - n2;
        success = true;
    } else if (op == '*') {
        current_res = n1 * n2;
        success = true;
    } else if (op == '/') {
        if (n2 == 0.0) {
            cout << "operacao nao pode ser realizada" << endl;
            current_res = n1;
            success = false;
        } else {
            current_res = n1 / n2;
            success = true;
        }
    }

    if (success) {
        cout << current_res << endl;
    }

    double next_num;
    while (cin >> next_num >> op && op != '&') {
        success = false;
        if (op == '+') {
            current_res += next_num;
            success = true;
        } else if (op == '-') {
            current_res -= next_num;
            success = true;
        } else if (op == '*') {
            current_res *= next_num;
            success = true;
        } else if (op == '/') {
            if (next_num == 0.0) {
                cout << "operacao nao pode ser realizada" << endl;
                success = false;
            } else {
                current_res /= next_num;
                success = true;
            }
        }

        if (success) {
            cout << current_res << endl;
        }
    }

    return 0;
}