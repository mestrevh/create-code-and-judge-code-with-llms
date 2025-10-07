/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        string spaces(n - i, ' ');
        string xes(2 * i, 'X');
        cout << spaces << xes << endl;
    }

    int trunk_height = n / 2;
    string trunk_spaces(n - 1, ' ');
    for (int i = 0; i < trunk_height; ++i) {
        cout << trunk_spaces << "XX" << endl;
    }

    return 0;
}
