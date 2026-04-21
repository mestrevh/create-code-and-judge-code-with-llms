/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int current;
    if (!(cin >> current) || current == 0) {
        cout << "EM ORDEM" << endl;
        return 0;
    }

    int previous = current;
    bool is_ordered = true;

    while (cin >> current && current != 0) {
        if (current <= previous) {
            is_ordered = false;
        }
        previous = current;
    }

    if (is_ordered) {
        cout << "EM ORDEM" << endl;
    } else {
        cout << "FORA DE ORDEM" << endl;
    }

    return 0;
}