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

    long long n;
    if (!(cin >> n)) return 0;

    int tonic = (n / 100) % 7;
    int third = (n / 10) % 7;
    int fifth = n % 7;

    if (tonic == 0 && third == 2 && fifth == 4) {
        cout << "Acorde do satisfaz." << endl;
    } else if (tonic == 1 && third == 3 && fifth == 5) {
        cout << "Acorde re satisfaz." << endl;
    } else if (tonic == 2 && third == 4 && fifth == 6) {
        cout << "Acorde mi satisfaz." << endl;
    } else if (tonic == 3 && third == 5 && fifth == 0) {
        cout << "Acorde fa satisfaz." << endl;
    } else if (tonic == 4 && third == 6 && fifth == 1) {
        cout << "Acorde sol satisfaz." << endl;
    } else if (tonic == 5 && third == 0 && fifth == 2) {
        cout << "Acorde la satisfaz." << endl;
    } else if (tonic == 6 && third == 1 && fifth == 3) {
        cout << "Acorde si satisfaz." << endl;
    } else {
        cout << "Combinacao nao satisfaz." << endl;
    }

    return 0;
}