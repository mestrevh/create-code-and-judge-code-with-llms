/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    if (n >= 18) {
        cout << "adulto" << "\n";
    } else if (n >= 10) {
        cout << "adolescente" << "\n";
    } else {
        cout << "crianca" << "\n";
    }

    return 0;
}